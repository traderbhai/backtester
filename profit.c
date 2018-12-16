#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
float *profit(int count, int fbtrade, int fstrade, int ttrades, int ltrade, float *tradelist)
{
    float *profit = malloc(sizeof(float)*count);
    int i;
    float tprofit=0;
    if(fbtrade<fstrade)
    {

        for(i=0;i<ttrades;i++)
        {
            profit[i]=-tradelist[i]-tradelist[i+1];
            tprofit=tprofit+profit[i];
        }

        if(tradelist[ltrade]=1)
                {
                   tprofit=tprofit-profit[ttrades-1];
                   profit[ttrades-1] = 0;
                }
    }
    else if (fbtrade>fstrade)
    {

        for(i=0;i<ttrades;i++)
        {
            profit[i]=-tradelist[i]-tradelist[i+1];
            tprofit=tprofit+profit[i];
        }
        if(tradelist[ltrade]=-1)
                {
                   tprofit=tprofit-profit[ttrades-1];
                   profit[ttrades-1] = 0;
                }
    }

    return profit;

}
