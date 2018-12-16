#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
int *sell(int count, float *datavalue,float *mag)
{
    int *sell = malloc(sizeof(float)*count);
    int i;
    sell[0]=0;
    for(i=0;i<count;i++)
    {
        if((datavalue[i]>mag[i]) && (datavalue[i+1]<mag[i+1]))
            sell[i+1]=-1;
        else
            sell[i+1]=0;
    }

    return sell;

}
