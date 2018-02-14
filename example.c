/*
 ============================================================================
 Name        : example.c
 Author      : Jiri Slezka
 Version     :
 Copyright   : MIT
 Description : Example of cayenne_lpp use
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cayenne_lpp.h"


int main(void) {

	struct CayenneLPP *lpp;
	unsigned char *buf;
	int w, size;

	puts("CayenneLPP test");

	lpp = CayenneLPP__create(51);
	printf("size %d\n", CayenneLPP__getSize(lpp));

	CayenneLPP__addTemperature(lpp, 1, 22.5);
	printf("size %d\n", CayenneLPP__getSize(lpp));

	CayenneLPP__addBarometricPressure(lpp, 2, 1073.21);
	printf("size %d\n", CayenneLPP__getSize(lpp));

	CayenneLPP__addGPS(lpp, 3, 52.37365, 4.88650, 2);
	printf("size %d\n", CayenneLPP__getSize(lpp));

	buf=CayenneLPP__getBuffer(lpp);
	size=CayenneLPP__getSize(lpp);
	for (w = 0; w < size; ++w) {
		printf("%02x ", buf[w]);
	}

	return EXIT_SUCCESS;
}
