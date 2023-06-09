#include <stdio.h> 
int main(void){
    enum Trafficlight {red, yellow, green};
    enum Trafficlight myTrafficLight = red;
    
    char keyPressed = 's';
    while(keyPressed != 'q') {
        switch(myTrafficLight){
            case red:
                printf("STOP !!!\n");
                myTrafficLight = yellow;
                break;
            case yellow:
                printf("Time to slow down !\n");
                myTrafficLight = green;
                break;
            case green:
                printf("GO !\n");
                myTrafficLight = red;
        }
        keyPressed = getchar();
    }
    return 0;
}
