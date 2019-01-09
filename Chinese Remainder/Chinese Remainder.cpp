#include<bits/stdc++.h>
using namespace std;

int d,x,y;

void euclid(int a,int b)
{
   if(a==0)
   {
     d=b;
     x=0,y=1;
   }

   else
   {
     euclid(b%a,a);
     int temp = y;
     y = x;
     x = temp - (b/a)*x;
   }
}

int modInverse(int a,int m)
{
   euclid(a,m);
   return (x%m+m)%m;
}

int findNum(int num[],int rem[],int n)
{
   int prod = 1;
   int res = 0;

   for(int i=0;i<n;i++)
     prod *= num[i];

     for(int i=0;i<n;i++)
     {
        int pp = prod/num[i];

        res+=rem[i]*pp*modInverse(pp,num[i]);
     }

     return res%prod;
}

int main()
{
   int num[] = {3,4,5};
   int rem[] = {2,3,1};

   int n = sizeof(num)/sizeof(num[0]);

   cout<<findNum(num,rem,n);
}
