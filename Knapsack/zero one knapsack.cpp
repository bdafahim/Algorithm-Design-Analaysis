#include<bits/stdc++.h>
using namespace std;

int knapsack(int weight[],int value[],int capacity,int n)
{
   int dp[n+1][capacity+1];
   int k;

   for(int i=0;i<=n;i++)
   {
      k=i-1;

      for(int j=0;j<=capacity;j++)
      {
         if(i==0 || j==0)
            dp[i][j] = 0;

          else if(weight[k]<=j)
            dp[i][j] = max(value[k]+dp[k][j-weight[k]],dp[k][j]);

            else
                dp[i][j] = dp[k][j];
      }
   }

   return dp[n][capacity];
}

int main()
{
   int capacity,number;

   printf("Enter Item number \n");
   cin>>number;

   printf("Enter capacity \n");
   cin>>capacity;
   int value[number],weight[number];

   printf("Enter the weights \n");
   for(int i=0;i<number;i++)
      cin>>weight[i];

      printf("Enter the weights\n");
      for(int i=0;i<number;i++)
      cin>>value[i];

      printf("%d",knapsack(weight,value,capacity,number));

    return 0;
}
