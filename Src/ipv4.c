#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char * ipv4()
{
	srand(time(NULL));
	char * ip = (char *) malloc(18);
	snprintf(&ip[0], 18,"%d.%d.%d.%d", (rand() % 256), (rand() % 256), (rand() % 256), (rand() % 256));
	
	return(ip);
}
