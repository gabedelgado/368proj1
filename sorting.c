#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


long * Load_File(char * Filename, int * size)
{
	FILE * dafile; 
	dafile = fopen(Filename, "r");

	if (dafile == NULL)
	{
		printf("File not could not be opened! \n");
	}
	

	fscanf(dafile, "%d", size);
	long * array = (long *)malloc(*size * sizeof(long));
	int i;
	for (i = 0; i < *size; i++)
	{
		fscanf(dafile, "%li", &array[i]);
	}
	
	fclose(dafile);
	
	return array;
}

int genseq1(int * array, int N)
{
	
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
	return (lead-2);

}

void Save_Seq1(char * Filename, int N)
{
	
	int * array = (int *)calloc(N, sizeof(int));
	
	FILE * writefile = fopen(Filename, "w");
	
	genseq1(array, N);
	int count = 0; 
	
	while (array[count] != 0)
	{
		fprintf(writefile, "%d\n", array[count]);
		count++;
	}
	
	fclose(writefile);
}

void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
	int * seqarray = (int *)calloc(Size, sizeof(int));
	int lastseqnum;
	lastseqnum = genseq1(seqarray, Size);
	int index1 = 0;
	int temp = 0;
	int index2 = 0;
	int temp2 = 0;
	int checkvar = 0;
	while (lastseqnum >= 0)
	{
		index1 = 0;		
		while ((index1 + seqarray[lastseqnum]) < (Size))
		{
			*N_Comp = *N_Comp + 1;			
			if ((Array[index1]) > (Array[index1 + seqarray[lastseqnum]]))
			{
				temp = Array[index1];
				Array[index1] = Array[index1+seqarray[lastseqnum]];
				Array[index1+seqarray[lastseqnum]] = temp;
				*N_Move = *N_Move + 3;
				index2 = index1;
				checkvar = 1;
				while (((index2 - seqarray[lastseqnum]) >= 0) && checkvar)
				{
					*N_Comp = *N_Comp + 1;
					checkvar = 0;					
					if(Array[index2] < (Array[index2 - seqarray[lastseqnum]]))
					{
						checkvar = 1;
						temp2 = Array[index2];
						Array[index2] = Array[index2 - seqarray[lastseqnum]];
						Array[index2 - seqarray[lastseqnum]] = temp;
						*N_Move = *N_Move + 3;
					}
					if (checkvar)
					{
						index2 = index2 - seqarray[lastseqnum]; 
					}		
				}
			}
			index1++;		
		}
		lastseqnum--;
	}

}

void Improved_Bubble_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{

	
}


int Save_File(char * Filename, long * Array, int Size)
{
	FILE * writefile = fopen(Filename, "w");
	int count = 0;
	
	while (count < Size)
	{
		fprintf(writefile, "%li\n", Array[count]);
		count++;
	}

	fclose(writefile);
	return (count);
}	
