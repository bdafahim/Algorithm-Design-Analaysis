#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 20

struct DataItem{
    int data;
    int key;
};

struct DataItem *dataList[SIZE][SIZE];
struct DataItem *singleItem;
struct DataItem *item;

int getHashCode(int key){
    ///get the hash
    return key%SIZE;
}


void Insert(int key,int data){
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));

    item->data = data;
    item->key = key;

    ///get the hash

    int hashIndex = getHashCode(key);

//    if(dataList[hashIndex][0]==NULL || dataList[hashIndex][0]==-1 )
//    dataList[hashIndex][0] = item;

    int k = 0;
    ///move  index untill find an empty
    while(dataList[hashIndex][k]!=NULL && dataList[hashIndex][k]!=-1)
    {

      ++k;
       hashIndex%=SIZE;
    }

    dataList[hashIndex][k] = item;




}

struct DataItem* Search(int key){
    int hashIndex = getHashCode(key);

    int j=0;
    while(dataList[hashIndex][j]!=NULL){
    ///match the key
       if(dataList[hashIndex][j]->key == key)
       return dataList[hashIndex][j];

       ///match for the next , go to next cell
       //++hashIndex;

       ///confirm the index within List
       hashIndex%=SIZE;
       j++;


    }

    return NULL;
}

struct DataItem *del(struct DataItem *item){

     int key = item->key;

     int hashIndex = getHashCode(key);

     int g=0;
     while(dataList[hashIndex][g]!=NULL){

      if(dataList[hashIndex][g]->key == key){
         struct DataItem *temp = dataList[hashIndex][g];

         ///assign a dummy position
         dataList[hashIndex][g] = singleItem;
         return temp;

         }

         ///go to next cell
         ///++hashIndex;

         hashIndex%=SIZE;
         g++;

     }

     return NULL;


}

void display(){
int i=0,j=0;
     for(i=0;i<SIZE;i++){
     for(int j=0;j<SIZE;j++){
        if(dataList[i][j]!=NULL)
        printf("  ( key=%d data=%d )  ",dataList[i][j]->key,dataList[i][j]->data);

        else printf("~");
        }
     }

     printf("\n");
}

int main(){

   singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));

   singleItem->data = -1;
   singleItem->key = -1;

   Insert(1,20);
   Insert(21,40);
   Insert(1,50);
   Insert(2,30);
   Insert(22,60);
   Insert(4,25);
   Insert(44,32);
   Insert(26,11);
   Insert(6,78);
   //Insert(7,97);

   display();

   item = Search(21);


   if(item!=NULL){
      printf("Element found : key = %d, data = %d\n",item->key,item->data);
   }
   else
   printf("Element not found\n");

////   item Search(1);
////
////   if(item!=NULL){
////      printf("Element found : key = %d, data = %d\n",item->key,item->data);
////   }
////   else
////   printf("Element not found\n");


   del(item);
   item = Search(21);

   if(item!=NULL){
      printf("Element found : key = %d, data = %d\n",item->key,item->data);
   }
   else
   printf("Element not found\n");


  return 0;
}

