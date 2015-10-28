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
//---------------------------------------------------------------------------------
//   Function:    main()
//
//   Title:       Standard Deviation Calculator
//
//   Description: 
//                Reads data from file.
//				  Calculates mean, variance, standard deviation
//				  Writes to new file
//
//   Programmer:  Scott Little
//   
//   Date:        10/24/2015
// 
//   Version:     1.01
//  
//   Environment: Intel i7 PC 
//                Software:   MS Windows 10 for execution; 
//                Compiles under Microsoft Visual Studio.Net 2013
//
//   Output:      # of data, sum, range, mean, variance, standard deviation
//
//   Calls:       fscanf, fprintf
//
//   Returns:     EXIT_SUCCESS (successful execution)
//
//   History Log:	10/24/2015 updated header info, updated code, added fprintf commands
//					10/28/2015 fixed read/write errors, calculation errors
// ------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	FILE * inFileHandle = NULL;		// handles existing input file
	FILE * outFileHandle = NULL;	// handles nonexisting output file
	char filename[FILENAME_MAX];	// holds either in file [1] or out file [2]
	char filename2[FILENAME_MAX];	// holds output file filename
	char c = ' ';					// initializes c is char type
	int maxLineSize = 0;			// amount of inputs per line
	int num = 0;					// num: individual inputs from each line
	int sum = 0;					// inputs added together
	int sumOfSquares = 0;			// each input squared added together
	int largest = INT_MIN;			// largest number in each data line
	int smallest = INT_MAX;			// smallest number in each data line
	int dataCount = 0;				// numbers per line
	double mean = 0;				// average value of data
	double variation = 0;			// range from smallest/largest values compared to mean
	double stdDeviation = 0;		// standard deviation

	// Header of program
	puts("Standard Deviation Program\n");
	puts("___________________________\n");
	puts("Written by Scott Little\n");
	// ask user for name of source file, assign to filename
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
		printf("Enter the name of the file to write (output): \n");
		scanf("%s", filename2);
	// alert user if output file cannot be opened
	if ((outFileHandle = fopen(filename, "a")) == NULL)
	{
	
	fclose(inFileHandle);
		printf("Could not open file %s for output.\n"
			"Press any key to continue", filename2);
		getch();
		return EXIT_FAILURE;
	}
	// opens output file, writes header to file
	outFileHandle = fopen(filename2, "w");
	fprintf(outFileHandle, "The results from file %s are:\n", filename);
	fprintf(outFileHandle, "_________________________________________________________________________________________________________________\n");
	fprintf(outFileHandle, "|# of data|\tsum\t|\trange\t|\tmean\t|\tvariance\t|\tstandard deviation\t|\n");
	fprintf(outFileHandle, "_________________________________________________________________________________________________________________\n");
	// scan data from input file, do math/conversions, output data to output file
	while (fscanf(inFileHandle, "%d", &maxLineSize) == 1)
	{
		for (int j = 0; j < maxLineSize; j++)
		{
			fscanf(inFileHandle, "%d", &num);
			sum += num;
			largest = num > largest ? num : largest;
			smallest = num < smallest ? num : smallest;
			sumOfSquares += pow(num, 2);
		}
		dataCount += maxLineSize;
		mean = (double)sum / (double)dataCount;
		variation = (sumOfSquares - (pow(sum, 2) / dataCount)) / (dataCount - 1);
		stdDeviation = sqrt(variation);
		fprintf(outFileHandle, "|%9d|%13d|%5i to %-6i|%15.3f|%23.3f|%31.3f|\n", dataCount, sum, smallest, largest, mean, variation, stdDeviation);
		fprintf(outFileHandle, "_________________________________________________________________________________________________________________\n");
	}
	// close files, confirms successful to user
	fclose(inFileHandle);
	fclose(outFileHandle);
	puts("\nSuccess!");
	puts("Press any key to Continue");
	getch();
	// returns EXIT_FAILURE
	return EXIT_FAILURE;

}
