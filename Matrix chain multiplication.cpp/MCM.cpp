#include<bits/stdc++.h>
using namespace std;

int MatrixChain(int m[],int i,int j)
{
   if(i==j)
      return 0;

      int ans = INT_MAX;

      for(int k=i;k<j;k++)
      {
         int temp = MatrixChain(m,i,k)+MatrixChain(m,k+1,j)+m[i-1]*m[k]*m[j];
         ans = min(ans,temp);
      }

    return ans;
}


int main()
{
  int matrices[] = {1,2,3,4,3};

  int n = sizeof(matrices)/sizeof(matrices[0]);
  cout<<"Minimum no. of operations : "<<MatrixChain(matrices,1,n-1)<<endl;

  return 0;
}
