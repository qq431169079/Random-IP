#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char alphabet[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
char * ip;

char * ipv6() {
    
    ip = (char *) malloc(22);
    
    srand(time(NULL));
    for(int i=0;i < 21; i++) {
        if((rand() % 2) == 1) {
            /* Generate random letter */
            if((i % 5) == 0) {
				sprintf(&ip[0], "%s:", ip);
			} else {
				sprintf(&ip[0], "%s%c", ip, alphabet[(rand() % 6)]);
			}
        } else {
            /* Generate random number */
            if((i % 5) == 0) {
				sprintf(&ip[0], "%s:", ip);	
			} else {
				sprintf(&ip[0], "%s%d", ip, (rand() % 10));
			}
        }
    }
	snprintf(&ip[0], 22,"%s::", &ip[1]);
	return(ip);
}
