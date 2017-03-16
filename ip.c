/*
 * ip.c
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

//Includes for needed librarys
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ip.h"

//Managing command line inputs
int ipv6e = 0; //Ipv6 enable
int ipv4e = 0; //Ipv4 enable
int num = 0; //Number of IPs to be generated
int roe = 0; //Raw output enable

int main(int argc, char *argv[]) {
	
	//Checks if no input given if no input display usage information
	if(!(argc > 1)) {
		printf("Usage: ranip [-n 99] [-ipv4] [-ipv6] [-ro] \n");
		printf("-n Print n number of addresses\n");
		printf("-ipv4 Print a random ipv4 address\n");
		printf("-ipv6 Print a random ipv6 address\n");
		printf("-ro Print output raw\n");
		return 0;
	}
	
	//Command line inputs
	for(int i = 1; i < argc; i++) {
		if(strcmp(argv[i], "-n") == 0) {
			num = atoi(argv[(i+1)]);
			i++;
		} else if(strcmp(argv[i], "-ipv6") == 0) {
			ipv6e = 1;
		} else if(strcmp(argv[i], "-ipv4") == 0) {
			ipv4e = 1;
		} else if(strcmp(argv[i], "-ro") == 0) {
			roe = 1;
		} else {
			printf("INVALID ARGUMENT\n");
			return 0;
		}
	}
	
	//Output IP/s
	if(num != 0) {
		for(int i = 0; i < num; i++) {
			if(ipv4e == 1) {
				if(!(roe == 1)) {
					printf("IPV4:%s\n", ipv4());
				} else {
					printf("%s", ipv4());
				}
			} else if(ipv6e == 1) {
				if(!(roe == 1)) {
					printf("IPV6:%s\n", ipv6());
				} else {
					printf("%s", ipv6());
				}
			}
		}
	} else if(ipv4e == 1) {
		if(!(roe == 1)) {
					printf("IPV4:%s\n", ipv4());
				} else {
					printf("%s", ipv4());
				}
	} else if(ipv6e == 1) {
		if(!(roe == 1)) {
					printf("IPV6:%s\n", ipv6());
				} else {
					printf("%s", ipv6());
				}
	}
	
	return 0;
}
