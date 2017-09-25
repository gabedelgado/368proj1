#include <stdio.h>
#include <stdlib.h>
#include <sorting.h>


long * Load_File(char * Filename, int * size)
{
	FILE * dafile; 
	dafile = fopen(Filename, "r");

	if (dafile == NULL)
	{
		printf("File not could not be opened! \n");
	}
	

	fscanf(dafile, "%d", size);
	long * array[*size];

	for (int i = 0; i < *size; i++)
	{
		fscanf(dafile, "%li", array[i]);
	}
	
	fclose(Filename);
	
	return * array;
}

void genseq1(int * array, int N)
{
	

	
}

