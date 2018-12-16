#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE_NAME 80
float  *datavalue(int count,char filename[MAX_FILE_NAME]);
int filecount(char filename[MAX_FILE_NAME]);
float *mavg(int count, int k, float *datavalue);
int *buy(int count, float *datavalue,float *mag);
int *sell(int count, float *datavalue,float *mag);
float *tradelist(int count, int ftrade, float *datavalue,int *buys,int *sells);
float *profit(int count, int fbtrade, int fstrade, int ttrades, int ltrade, float *tradelist);


int main()
 {
   int i = 0,count=0,k,ttrades;
   float tprofit=0, avgpnl=0;
   int ftrade,fbtrade,fstrade,ltrade,btrades=0,strades=0;
   float *array=NULL;
   char filename[MAX_FILE_NAME];
   float *mag=NULL;
   float *tradelists=NULL;
   int *buys=NULL;
   int *sells=NULL;
   float *profits=NULL;

   printf("Enter file name or full path: ");
   scanf("%s", filename);
   printf("\nEnter the rolling period: ");
   scanf("%d", &k);
   count=filecount(filename);
   array = datavalue(count,filename);
   mag=mavg(count,k,array);
   buys=buy(count,array,mag);
   sells=sell(count,array,mag);

/****************************************
Finding the first signal, First Buy Signal, First Sell Signal, LAST TRADE
*******************************************/
    for(i=0;i<count;i++)
    {
        if(buys[i]==1 || sells[i]==-1)
        {
            ftrade=i;
            break;
        }
    }
     for(i=0;i<count;i++)
     {
         if(buys[i]==1)
        {
            fbtrade=i;
            break;
        }
     }
     for(i=0;i<count;i++)
     {
         if(sells[i]==-1)
        {
            fstrade=i;
            break;
        }
     }
    for(i=0;i<count;i++)
    {
        if(buys[i]==1 || sells[i]==-1)
        {
            ltrade=i;
        }
    }

for(i=0;i<count;i++)
    {
        if(buys[i]==1)
        btrades=btrades+1;
        else if(sells[i]==-1)
        strades=strades+1;
    }
/*******************************
Making Trade List and profit calculation array tradelists[]
*********************************************/
    ttrades=btrades+strades;
    tradelists=tradelist(count,ftrade,array,buys,sells);
/*******************************
Profit Calculation array profits[]
*********************************************/
    profits=profit(count,fbtrade,fstrade,ttrades,ltrade,tradelists);
    for(i = 0; i<= ttrades; i++)
    {
        tprofit = tprofit+profits[i];
    }
    avgpnl=tprofit/ttrades;

/*******************************
printing
*********************************************/
        printf("\n=============================================================================");
        printf("\nData\tPrice\t        MA Value \tBuy Signal    \tSell Signal");
        printf("\n=============================================================================");
    for(i = 0; i< count; i++)
    {
        printf("\n[%d]\t%0.2f\t%0.2f    \t%d        \t%d",i,array[i],mag[i],buys[i],sells[i]);
    }

    printf("\n=============================================================================");
        printf("\n          PROFIT LOSS TABLE");
        printf("\n=============================================================================");
    for(i = 0; i<=ttrades; i++)
    {
        printf("\nProfit/Loss in Trade[%d] \t: %0.2f",i,profits[i]);
    }

     printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
     printf("\n+++++++++++++++              SUMMARY         ++++++++++++++++++++++++++++++++++");
     printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\nThe file has %d lines", count);
        printf("\nFirst trade started at A[%d]",ftrade);
        printf("\nLast trade signal at A[%d]",ltrade);
        printf("\nFirst Buy trade started at A[%d]",fbtrade);
        printf("\nFirst Sell trade started at A[%d]",fstrade);
        printf("\nTotal number of signals = %d",ttrades);
        printf("\nTotal Buy Signals = %d",btrades);
        printf("\nTotal Sell Signals = %d",strades);
        printf("\nThe Total Profit is %0.2f",tprofit);
        printf("\nThe Average Profit/Loss per trade is %0.2f",avgpnl);
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");


 }
