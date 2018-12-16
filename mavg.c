#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
float *mavg(int count, int k, float *datavalue)
        {
    float *mag = malloc(sizeof(float)*count);
    //float data[count];
	float avg=0,sum=0;
	int i;

	for(i=0;i<k-1;i++)
	{
	  mag[i]=0;
	  sum=sum+datavalue[i];
    }

	for(i=k-1;i<=count;i++)
	{
	    mag[i-1]=avg;
	    sum=sum + datavalue[i]- datavalue[i-k];
	    avg = sum / k;
    }
    return mag;


        }
