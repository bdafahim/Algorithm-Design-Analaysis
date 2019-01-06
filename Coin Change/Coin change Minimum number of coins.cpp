#include<bits/stdc++.h>
using namespace std;

int MinCoins(int coins[],int n,int C)
{
   int table[C+1];
   table[0] = 0;

   for(int i=1;i<=C;i++)
   table[i] = 99999;

   for(int i=1;i<=C;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(coins[j]<=i)
         {
            int sub_res = table[i-coins[j]];

            if(sub_res!=99999 && sub_res+1<table[i])
            table[i] = sub_res+1;
         }
      }
   }

   return table[C];
}

int main()
{
while(1){
   int n,C;
   printf("What coin do you want to make\n");
   cin>>C;
   int coins[C+1];

   printf("Number of given coins :\n");
   cin>>n;

   printf("Given coins :\n");
   for(int i=0;i<n;i++)
   cin>>coins[i];

   printf("Minimum no. of coins : %d\n\n",MinCoins(coins,n,C));
   }
}
