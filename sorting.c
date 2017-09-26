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
	array = (int *)calloc(N, sizeof(int));
	
	int p2 = 0;
	int p3 = 0;
	array[0] = 1;	
	int lead = 1;
	int u2 = 1;
	int u3 = 1;

	while(array[lead-1] < N)
	{
		if (array[p2] * 2 == array[lead-1])
		{
			p2 = p2 + 1;
		}
		if (array[p3] * 3 == array[lead-1])
		{
			p3 = p3 + 1;
		}
		u2 = array[p2] * 2;
		u3 = array[p3] * 3;
		
		if (u2 < u3)
		{
			p2 = p2 + 1;
			array[lead] = u2;
		}
		else
		{
			p3 = p3 + 1;
			array[lead] = u3;
		}
		lead++;
	}	
	array[lead-1] = 0;

}

void Save_Seq1(char * Filename, int N)
{
	
	int * array;
	FILE * writefile = fopen(Filename, "w");
	
	genseq1(array, N);
	int count = 0; 
	
	while (array[count] != 0)
	{
		fprintf(writefile, "%d\n", array[count]);
		count++;
	}
	
}



