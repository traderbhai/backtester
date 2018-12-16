#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
float *tradelist(int count, int ftrade, float *datavalue,int *buys,int *sells)
{
    float *tradelist = malloc(sizeof(float)*count);
    int j=0,i;
    for(i=ftrade;i<count;i++)
{
    if(buys[i]!=0)
    {
        tradelist[j]= datavalue[i];
        j++;
    }
    else if (sells[i]!=0)
    {
        tradelist[j]= -1*datavalue[i];
        j++;
    }
}
    return tradelist;
}
