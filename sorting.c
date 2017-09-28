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
	
	int result = 1;
	int lastnum = 0;	
	int numdiv = (int)(Size/1.3);
	while(numdiv != 1)
	{
		numdiv = (int)(numdiv/1.3);
		result++;
		
	}
	
	int * seqarray = (int *)calloc(result + 5, sizeof(int));
		
	lastnum = genseq2(seqarray, Size);

	int index = 0;
	int indexref = 0;
	int lastcheck = 0;
	int currentindex = 0;
	int temp = 0;	
	
	while(lastnum >=0)
	{				
		index = 0;		
		while(((index + seqarray[lastnum]) < Size) && (seqarray[lastnum] != index)) 
		{
			lastcheck = -1;
			indexref = index;						
			currentindex = indexref;			
			while(lastcheck != indexref)
			{
				
				while(((currentindex + seqarray[lastnum]) != lastcheck) && ((currentindex + seqarray[lastnum]) < Size))
				{
					*N_Comp = *N_Comp + 1;					
					if(Array[currentindex] > Array[currentindex + seqarray[lastnum]])
					{
						*N_Move = *N_Move + 3;						
						temp = Array[currentindex];
						Array[currentindex] = Array[currentindex + seqarray[lastnum]];
						Array[currentindex + seqarray[lastnum]] = temp;
					}
					currentindex = currentindex + seqarray[lastnum];

				}
				
				lastcheck = lastcheck - seqarray[lastnum];

				if((currentindex + seqarray[lastnum]) >= Size)
				{
					lastcheck = currentindex;
				}					
				currentindex = indexref;			
			}
			index++;
		}
		lastnum--;
	}
				
}

int genseq2(int * array, int N)
{
	
	int temp = N;
	temp = (int)(temp/1.3);
	int count = 1;	
			
	while(temp != 1)
	{
		temp = (int)(temp/1.3);
		count++;
	}
	
	int returnnum = count;

	temp = N;
	temp = (int)(temp/1.3);
		
		
	while(count >= 0)
	{
		if(temp == 9 || temp == 10)
		{
			temp = 11;
		}		
		array[count] = temp;
		temp = (int)(temp/1.3);		
		count--;
	}
		
	return returnnum;
}	
	
void Save_Seq2(char * Filename, int N)
{
	int result = 1;
	
	int numdiv = (int)(N/1.3);
	while(numdiv != 1)
	{
		numdiv = (int)(numdiv/1.3);
		result++;
		
	}
	
	int * array = (int *)calloc(result + 5, sizeof(int));
	
	genseq2(array, N);
	
	int count = 0; 
	
	FILE * writefile = fopen(Filename, "w");
	
	while (array[count] != 0)
	{
		fprintf(writefile, "%d\n", array[count]);
		count++;
	}
	
	fclose(writefile);
	
}

int Save_File(char * Filename, long * Array, int Size)
{
	FILE * writefile = fopen(Filename, "w");
	int count = 0;
	fprintf(writefile, "%d\n", Size);
	while (count < Size)
	{
		fprintf(writefile, "%li\n", Array[count]);
		count++;
	}

	fclose(writefile);
	return (count);
}	
