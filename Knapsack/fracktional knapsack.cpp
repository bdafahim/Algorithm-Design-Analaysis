#include<bits/stdc++.h>
using namespace std;


struct Item
{
   int value;
   int weight;
};

bool cmp(struct Item a,struct Item b)
{
   double ratio1 = (double)(a.value/a.weight);
   double ratio2 = (double)(b.value/b.weight);

   return ratio1>ratio2;
}

int main()
{
   Item items[] = {{60,10},{100,20},{120,30}};
   int allowedWeight = 50;
   int i=0;
   int n = sizeof(items)/sizeof(items[0]);

   sort(items,items+n,cmp);

   double current_value = 0.0;
   int current_weight = 0;

   for(int i=0;i<n;i++)
   {
      if(current_weight+items[i].weight<=allowedWeight)
      {
         current_value += items[i].value;
         current_weight += items[i].weight;
      }

      else
      {
         int remainingWeight = allowedWeight - current_weight;
         double  valueOfRemainingWeight = items[i].value*(double)remainingWeight/items[i].weight;
         current_weight += remainingWeight;
         current_value += valueOfRemainingWeight;
         break;

      }
   }

   printf("%f %d",current_value,current_weight);

}
