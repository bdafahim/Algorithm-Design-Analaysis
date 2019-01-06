#include<bits/stdc++.h>
using namespace std;

int NumberOfWays(int coins[],int n,int C)
{
   int table[C+1];
   memset(table,0,sizeof(table));
   table[0] = 1;

   for(int i=0;i<n;i++)
     for(int j=coins[i];j<=C;j++)
       table[j] += table[j-coins[i]];

       return table[C];
}

int main()
{
   int coins[] = {1,2,3};
   int n = sizeof(coins)/sizeof(coins[0]);
   int C = 6;

   printf("No. of ways to make %d is : %d\n",C,NumberOfWays(coins,n,C));

}
