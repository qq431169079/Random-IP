/*
 * ipv6.c
 * 
 * Copyright 2017 Fraser <fraser@fraser-Aspire-6920>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

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
