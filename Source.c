//----------------------------------------------------------------------------
// File: Source.c
// Functions:
//		int main(int argc, char *argv[])
//----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 256
#pragma warning(disable: 4996) 
//*-----HEADER*------*//
int main(int argc, char *argv[])
{
	FILE * inFileHandle = NULL; // handles existing input file
	FILE * outFileHandle = NULL; // handles nonexisting output file
	char filename[FILENAME_MAX]; // array to hold either in file [1] or out file [2]
	char filename2[FILENAME_MAX];
	char input[MAX];
	char c = ' ';
	int maxLineSize = 0, num = 0;
	int sum = 0, sumOfSquares = 0, largest = INT_MIN, smallest = INT_MAX, dataCount = 0;
	double mean = 0, variation = 0, stdDeviation = 0;

	// Header of program
	puts("Standard Deviation Program\n");
	puts("___________________________\n");
	puts("Written by Scott Little\n");

	puts("Enter the name of the file to read (source):");
	fgets(filename, FILENAME_MAX, stdin);
	
	// delete "\n" returned by fgets after string
	if (filename[strlen(filename) - 1] == '\n')
		filename[strlen(filename) - 1] = '\0';
	else
		while (getchar() != '\n')
			;
	// if file not found, exit
	if ((inFileHandle = fopen(filename, "r")) == NULL)
	{
		fprintf(stdout, "Can't open file.\n");
		puts("Press any key to exit.");
		getchar();
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		strncpy(filename, argv[2], FILENAME_MAX);
	}
	else
	{
		printf("Enter the name of the file to write (output): \n");
		scanf("%s", filename2);
	}
	if ((outFileHandle = fopen(filename, "a")) == NULL)
	{
	
	fclose(inFileHandle);
		printf("Could not open file %s for output.\n"
			"Press any key to continue", filename2);
		getch();
		return EXIT_FAILURE;
	}

	outFileHandle = fopen(filename2, "w");	//Opens output file from user input
	fprintf(outFileHandle, "The results from file %s are:\n", filename);
	fprintf(outFileHandle, "_________________________________________________________________________________________________________________\n");
	fprintf(outFileHandle, "|# of data|\tsum\t|\trange\t|\tmean\t|\tvariance\t|\tstandard deviation\t|\n");
	fprintf(outFileHandle, "_________________________________________________________________________________________________________________\n");
	while (fscanf(inFileHandle, "%d", &maxLineSize) == 1)
	{
		for (int j = 0; j < maxLineSize; j++)
		{
			fscanf(inFileHandle, "%d", &num);
			sum += num;
			sumOfSquares = pow(num, 2);
			largest = num > largest ? num : largest;
			smallest = num < smallest ? num : smallest;
		}
		dataCount += maxLineSize;
		mean = (double)sum / (double)dataCount;
		variation = (sumOfSquares - (pow(sum, 2) / dataCount)) / (dataCount - 1);
		stdDeviation = sqrt(variation);
		fprintf(outFileHandle, "%6i %11i %12i to %-6i %8.3f %16.3f %24.3f \n", dataCount, sum, smallest, largest, mean, variation, stdDeviation);
	}
		/* 
			5
			5  7  3  6  6
			2
			-1  5
		*/

		/* sum += num;
		sumOfSquares = pow(num, 2);
		if (num > largest)
			largest = num;
		if (num < smallest)
			smallest = num;
		mean = sum / (i + 1); */
		//variance = (sum_of_squares - (pow(sum, 2)  sum_of_data_counts))  (sum_of_data_counts - 1);
		//standard_deviation = sqrt(variance);
		
		
		//if (c == ' ')
		//	c = '\n';
		//putc(c, outFileHandle);

		//fprintf(outFileHandle, "\nMean: %d", mean);
		//fprintf(outFileHandle, "%d", num);
		//getc(inFileHandle);
		//if ((c = (char)getc(inFileHandle)) == EOF)
		//	break;
	//}
	//fprintf(outFileHandle, "\nLargest: %d" "\nSmallest: %d", largest, smallest);
	/*while ((c = (char)getc(inFileHandle)) != EOF)
	{

		
		

		putc(c, outFileHandle);

	} */
	fclose(inFileHandle);
	fclose(outFileHandle);
	puts("\nPress any key to Continue");
	getch();

	return EXIT_FAILURE;

}
