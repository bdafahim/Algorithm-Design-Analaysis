#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n ;
   printf("Enter the size of the array\n");
   cin>>n;

   int arr[n+1];

   for(int i=0;i<n;i++)
       cin>>arr[i];

   int lis[n+1],mx = 0;

   for(int i=0;i<n;i++)
      lis[i] = 1;

      for(int i=1;i<=n;i++)
       {
          for(int j=0;j<i;j++)
          {
             if(arr[i]>arr[j] && lis[j]+1>lis[i]){
                lis[i] = lis[j]+1;

                if(mx<lis[i])
                    mx = lis[i];

                }
          }


       }

       printf("LIS : %d",mx);



}
