// fix this code to improve its reliability

#include <stdio.h>
#include <unistd.h>  // for sleep

int main( ) {
    int sensor1;
    int sensor2;
    
    while (1) {
        if (sensor1 > 25) {
            printf("cooling on\n");
        }
        else if 
            ((sensor1 >= 18) && (sensor1 <= 25)) {
            printf("Standby\n");
        }
        else if (sensor1 < 18) {
            printf("heating on\n");
        }
        
        sleep(3); // this makes the program pause for 5 seconds in unix
        // read new sensor value
        scanf("%d", &sensor1);
        scanf("%d", &sensor2);
    }
}

