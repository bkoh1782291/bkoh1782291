#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "emulator.h"
#include "gbn.h"

/* ******************************************************************
  Selective Repeat Protocol

   Differences to Go Back N protocl
   1. sender window size is always same as receiver window size.
   2. uses independent acknowledgements only.
   3. does not accept the corrupted frames but does not silently discard them.
   4. accepts the out of order frames.
   5. requires sorting at the receiver’s side.
   6. protocol requires searching at the sender’s side.
   7. retransmission of lost frames after expiry of timeout timer.

   [x] basic functionality
   [x] pipelining with full window
   [x] lost ACKs/ timeout handling
   [x] handle corrupted packets
   [x] handle corrupted ACKs
   [?] delivery of previous buffered packets
   [x] handles lost packet
   [x] duplicate packet & duplicate ACK
   [?] handles mixed events, window management and high message volumes

**********************************************************************/

#define RTT 15.0      /* round trip time.  MUST BE SET TO 15.0 when submitting assignment */
#define WINDOWSIZE 6  /* Maximum number of buffered unacked packet */
#define SEQSPACE 15    /* min sequence space for GBN must be at least windowsize + 1 */
#define NOTINUSE (-1) /* used to fill header fields that are not being used */

/* generic procedure to compute the checksum of a packet.  Used by both sender and receiver
   the simulator will overwrite part of your packet with 'z's.  It will not overwrite your
   original checksum.  This procedure must generate a different checksum to the original if
   the packet is corrupted.
*/
int ComputeChecksum(struct pkt packet)
{
  int checksum = 0;
  int i;

  checksum = packet.seqnum;
  checksum += packet.acknum;
  for (i = 0; i < 20; i++)
    checksum += (int)(packet.payload[i]);

  return checksum;
}

bool IsCorrupted(struct pkt packet)
{
  if (packet.checksum == ComputeChecksum(packet))
    return (false);
  else
    return (true);
}

/********* Sender (A) variables and functions ************/

/********************** CHANGES MADE HERE *************************/
static struct pkt buffer[WINDOWSIZE]; /* array for storing packets waiting for ACK */
static int windowfirst, windowlast;   /* array indexes of the first/last packet awaiting ACK */
static int windowcount;               /* the number of packets currently awaiting an ACK */
static int A_nextseqnum;              /* the next sequence number to be used by the sender */
static int acked_packets[WINDOWSIZE]; /* array for storing packets that recived ACKs */


/* called from layer 5 (application layer), passed the message to be sent to other side */
void A_output(struct msg message)
{
  struct pkt sendpkt;
  int i;

  /* if not blocked waiting on ACK */
  if (windowcount < WINDOWSIZE)
  {
    if (TRACE > 1)
      printf("----A: New message arrives, send window is not full, send new messge to layer3!\n");

    /* create packet */
    sendpkt.seqnum = A_nextseqnum;
    sendpkt.acknum = NOTINUSE; /* assigned to -1 (see above) */

    for (i = 0; i < 20; i++)
    {
      sendpkt.payload[i] = message.data[i];
    }
    sendpkt.checksum = ComputeChecksum(sendpkt);

    /* put packet in window buffer */
    /* windowlast will always be 0 for alternating bit; but not for GoBackN */
    windowlast = (windowlast + 1) % WINDOWSIZE;
    acked_packets[windowlast] = 0;
    buffer[windowlast] = sendpkt;
    windowcount++;

    /* send out packet */
    if (TRACE > 0)
      printf("Sending packet %d to layer 3\n", sendpkt.seqnum);
    tolayer3(A, sendpkt);

    /* start timer if first packet in window */
    if (windowcount == 1)
      starttimer(A, RTT);

    /* get next sequence number, wrap back to 0 */
    A_nextseqnum = (A_nextseqnum + 1) % SEQSPACE;
  }
  /* if blocked,  window is full */
  else
  {
    if (TRACE > 0)
      printf("----A: New message arrives, send window is full\n");
    window_full++;
  }
}

/* called from layer 3, when a packet arrives for layer 4
   In this practical this will always be an ACK as B never sends data. */
void A_input(struct pkt packet)
{
  int ackcount = 0;
  int seq_count;                 /* indexing for sequence numbers */
  int expected_ack;              /* indexing for expected ACK in window */

  /* if received ACK is not corrupted */
  if (!IsCorrupted(packet))
  {
    if (TRACE > 0)
    {
      printf("----A: uncorrupted ACK %d is received\n", packet.acknum);
    }
    total_ACKs_received++;

    /********************** CHANGES MADE HERE *************************/
    /* check if new ACK or duplicate */
    expected_ack = A_nextseqnum - windowcount;
    if (expected_ack < 0)
    {
      expected_ack = expected_ack + SEQSPACE;
    }
    /* update the sequence count */
    /* packet index minus the expected ACK index */
    seq_count = packet.acknum - expected_ack;
    if (seq_count < 0)
    {
      seq_count = seq_count + SEQSPACE;
    }

    /* else just continue */

    /********************** CHANGES MADE HERE *************************/

    /* if there are packets waiting for ACK */
    if ((windowcount > 0) && (seq_count < WINDOWSIZE))
    {
      /* packet is a new ACK */
      if (TRACE > 0)
      {
        printf("----A: ACK %d is not a duplicate\n", packet.acknum);
      }
      new_ACKs++;
      ackcount = (seq_count + windowfirst) % WINDOWSIZE;
      acked_packets[ackcount] = NOTINUSE;

      /* Sliding Window implementation for SR */
      while ((windowcount > 0) && (acked_packets[windowfirst] == NOTINUSE))
      {
        /* slide window by the number of packets ACKed */
        windowfirst = (windowfirst + 1) % WINDOWSIZE;

        /* delete the ACKed packets from window buffer */
        windowcount--;
      }
      /********************** CHANGES MADE HERE *************************/
      /* restart timer if there are still un-ACKed packets in window */
      if (seq_count == 0)
      {
        stoptimer(A);
        if (windowcount > 0)
        {
          starttimer(A, RTT);
        }
      }
    }
    else if (TRACE > 0) /* duplicates does not need to be handled */
    {
      printf("----A: duplicate ACK received, do nothing!\n");
    }
}
  else if (TRACE > 0) /* corrupted ACK does not need to be handled */
  {
    printf("----A: corrupted ACK is received, do nothing!\n");
  }
}

/********************** CHANGES MADE HERE *************************/
/* called when A's timer goes off */
void A_timerinterrupt(void)
{
  if (TRACE > 0)
    printf("----A: time out,resend packets!\n");

  if (TRACE > 0)
    printf("---A: resending packet %d\n", (buffer[windowfirst]).seqnum);

  /*  resend the first packet from the window */
  tolayer3(A, buffer[windowfirst]);
  packets_resent++;

  if (windowcount > 0)
  {
    /* restart the timer for A */
    starttimer(A, RTT);
  }
}

/* the following routine will be called once (only) before any other */
/* entity A routines are called. You can use it to do any initialization */
void A_init(void)
{
  /* initialise A's window, buffer and sequence number */
  A_nextseqnum = 0; /* A starts with seq num 0, do not change this */
  windowfirst = 0;
  windowlast = -1; /* windowlast is where the last packet sent is stored.
		     new packets are placed in winlast + 1
		     so initially this is set to -1
		   */
  windowcount = 0;
}

/********* Receiver (B)  variables and procedures ************/

static int expectedseqnum;              /* the sequence number expected next by the receiver */
static int B_nextseqnum;                /* the sequence number for the next packets sent by B */
static struct pkt B_buffer[WINDOWSIZE]; /* array to store buffered packets in B */
static int B_windowfirst;               /* array indexes of the first/last packet awaiting ACK */

/* called from layer 3, when a packet arrives for layer 4 at B*/
void B_input(struct pkt packet)
{
  struct pkt sendpkt;
  int seq_count;                 /* indexing for sequence numbers */

  /* if not corrupted and received packet is in order */
  if ((!IsCorrupted(packet)))
  {
    if (TRACE > 0){
      printf("----B: packet %d is correctly received, send ACK!\n", packet.seqnum);
    }
    packets_received++;

    seq_count = packet.seqnum - expectedseqnum;
    if (seq_count < 0)
    {
      seq_count = seq_count + SEQSPACE;
    }

    if (seq_count < WINDOWSIZE)
    {
      /* sorting buffer */
      B_buffer[((B_windowfirst + seq_count) % WINDOWSIZE)] = packet;
      /* if -1 not found in buffer */
      while (B_buffer[B_windowfirst].seqnum != NOTINUSE)
      {
        /* deliver to reciever */
        tolayer5(B, B_buffer[B_windowfirst].payload);

        /* set first window[1] to -1 */
        B_buffer[B_windowfirst].seqnum = NOTINUSE;
        /* b = (b+1) mod (y) */
        B_windowfirst = (B_windowfirst + 1) % WINDOWSIZE;

        /* update state variables */
        expectedseqnum = (expectedseqnum + 1) % SEQSPACE;
      }
    }
  }
  else
  {
    /* packet is corrupted or out of order */
    /* Selective Repeat actually does not need this */
    if (TRACE > 0)
    {
      printf("----B: packet corrupted or not expected sequence number, do nothing !\n");
    }
  }

  /* send an ACK for the received packet */
  sendpkt.acknum = packet.seqnum;

  /* send sequence number for the next seqnum */
  sendpkt.seqnum = B_nextseqnum;
  B_nextseqnum = (B_nextseqnum + 1) % 2;

  /* we don't have any data to send.  fill payload with 0's */
  int i;
  for (i = 0; i < 20; i++)
  {
    sendpkt.payload[i] = '0';
  }

  /* computer checksum */
  sendpkt.checksum = ComputeChecksum(sendpkt);

  /* send out packet */
  tolayer3(B, sendpkt);
}

/* the following routine will be called once (only) before any other */
/* entity B routines are called. You can use it to do any initialization */
void B_init(void)
{
  int i;
  expectedseqnum = 0;
  B_nextseqnum = 1;
  B_windowfirst = 0;

  /* reset buffer array to -1 */
  for (i = 0; i < WINDOWSIZE; i++)
  {
    B_buffer[i].seqnum = NOTINUSE;
  }
}

/******************************************************************************
 * The following functions need be completed only for bi-directional messages *
 *****************************************************************************/

/* Note that with simplex transfer from a-to-B, there is no B_output() */
void B_output(struct msg message)
{
  /* leave blank */
}

/* called when B's timer goes off */
void B_timerinterrupt(void)
{
  /* leave blank */
}
