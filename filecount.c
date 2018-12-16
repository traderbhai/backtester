#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
int filecount(char filename[MAX_FILE_NAME])
{
    FILE *fp;
	int count0 = 0; // Line counter (result)
	char c; // To store a character read from file
	fp = fopen(filename, "r");

	// Check if file exists
	if (fp == NULL)
	{
		printf("Could not open file %s", filename);
		return 0;
	}

	// Extract characters from file and store in character c
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') // Increment count if this character is newline
			count0 = count0 + 1;

	// Close the file
	fclose(fp);
	return count0;
	//printf("The file %s has %d lines\n", filename, count);
}
