#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define MAX_HEIGHT 220
#define MID_HEIGHT 205
#define MIN_HEIGHT 190
#define MAX_WEIGHT 250
#define MID_WEIGHT 225
#define MIN_WEIGHT 200
#define MAX_POINTS 20
#define MID_POINTS 15
#define MIN_POINTS 10
#define MAX_REBOOT 6
#define MID_REBOOT 4
#define MIN_REBOOT 2
#define MAX_PASS 7
#define MID_PASS 5
#define MIN_PASS 3

int main() {
    uint16_t more_max = 0, more_mid = 0, more_min = 0, height = 0, N = 0, points = 0, reboot = 0, pass = 0;
    uint16_t weight = 0;
    scanf("%"SCNu16, &N);
    uint16_t i = 0;
    for(i = 0; i < N; ++i){
    	more_max = 0;
    	more_min = 0;
    	more_mid = 0;
        scanf("%"SCNu16, &height);
        scanf("%"SCNu16, &weight);
        scanf("%"SCNu16, &points);
        scanf("%"SCNu16, &reboot);
        scanf("%"SCNu16, &pass);
        if(height > MAX_HEIGHT){
        	++more_max;
        }else if(height >= MID_HEIGHT){
        	++more_mid;
        }else if(height >= MIN_HEIGHT){
        	++more_min;
        }

        if(weight > MAX_WEIGHT){
        	++more_max;
        }else if(weight >= MID_WEIGHT){

        	++more_mid;
        }else if(weight >= MIN_WEIGHT){

        	++more_min;

        }

        if(points > MAX_POINTS){
        	++more_max;
        }else if(points >= MID_POINTS){

        	++more_mid;
        }else if(points >= MIN_POINTS){

        	++more_min;

        }

        if(reboot > MAX_REBOOT){
        	++more_max;
        }else if(reboot >= MID_REBOOT){

        	++more_mid;
        }else if(reboot >= MIN_REBOOT){

        	++more_min;

        }

        if(pass > MAX_PASS){
        	++more_max;
        }else if(pass >= MID_PASS){

        	++more_mid;
        }else if(pass >= MIN_PASS){

        	++more_min;

        }

        if((height > MAX_HEIGHT || weight > MAX_WEIGHT) && more_max >= 3){
            printf("0\n");
        }else if((more_mid + more_max - 2 >= 1 && more_max >= 2) || (more_min+more_mid+more_max == 5 && more_mid + more_max >= 3)){
        	printf("1\n");
        }else if((more_max >= 1 && more_mid + more_max - 1 >= 1) || (more_mid >= 3)){
        	printf("2\n");
        }else{
        	printf("3\n");
        }
    }
	return 0;
}