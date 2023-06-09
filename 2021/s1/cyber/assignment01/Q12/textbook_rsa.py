# function to calculate inverse modular
# using the extended Euclidean algorithm
import binascii

def invmod(a,n):
  i=1
  while True:
    c = n * i + 1;
    if(c%a==0):
      c = c/a
      break;
    i = i+1
  return c

p = int("C5A047A7C52ED3A2875F7D76C47B555F",16) # first prime
q = int("C93268355C09197BBF1659B5522FFACD",16) # second prime
e = int("010001",16) # an number that is co-prime with (p-1)*(q-1)

# convert string to integer using
def string_to_int(string):
    return int.from_bytes(binascii.a2b_qp(string),byteorder='big')

# convert into back to string
def int_to_string(number):
    bin = number.to_bytes((number.bit_length() + 7) // 8, byteorder='big')
    return binascii.b2a_qp(bin).decode("utf-8")

# calculate modulus n
#n = p*q
n = int("9B51C20306EDE535C8FCAADBC3F3515E52A0D005703DD449BEC66B23E2932313", 16)
print("n is: " + str(n))

# calculate inverse modular d of exponent e and (p-1)*(q-1)
#d = invmod(e, (p-1)*(q-1))
d = int("0D067636BAC6088AD2281E4BFFCACFEFEF9BC1A69FB9E701063DFBAAB436E4C1", 16)
print("d is: " + str(d))

# check that d*e mod (p-1)*(q-1) is indeed 1
print("checking d*e mod (p-1)*(q-1): " + str(((d*e) % ((p-1)*(q-1)))))
print('\n')

# encrypting short message using public exponent e
# msg = int("13121ff7d7be2301a4db5801d6d142e9bb3fbef7f4c73c14f647d5f43ebc8db3",16)
# enc = pow(msg,e, n) # supplying the 3rd parameter efficiently computes the mod
# print "Message " + str(msg) + " is encrypted to: " + str(enc)

# decrypt message using private exponent d
enc = int("13121ff7d7be2301a4db5801d6d142e9bb3fbef7f4c73c14f647d5f43ebc8db3", 16)
plain = pow(enc,d, n) # supplying the 3rd parameter efficiently computes the mod
print("Cipher " + str(enc) + " is decrypted to: " + str(plain))
print('\n')
print("csf format:  " +  int_to_string(plain)) 
