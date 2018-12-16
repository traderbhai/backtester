#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
float  *datavalue(int count,char filename[MAX_FILE_NAME])
{

    float *numberArray = malloc(sizeof(float)*count);

    FILE *fp;
    fp = fopen(filename, "r");
   //read file into array

   int i;

  if (fp == NULL) {
      printf("Error Reading File\n");
      exit (0);
  }

  for (i = 0; i <= count; i++)
  {
      fscanf(fp, "%f,", &numberArray[i]);

  }

 fclose(fp);
 return numberArray;
}
