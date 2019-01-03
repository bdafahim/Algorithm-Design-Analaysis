#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 20

struct DataItem{
    int data;
    int key;
};

struct DataItem *dataList[SIZE];
struct DataItem *singleItem;
struct DataItem *item;

int getHashCode(int key){
    ///get the hassh
    return key%SIZE;
}


void Insert(int key,int data){
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));

    item->data = data;
    item->key = key;

    ///get the hash

    int hashIndex = getHashCode(key);

    ///move  index untill find an empty
    while(dataList[hashIndex]!=NULL && dataList[hashIndex]!=-1)
    {
       ++hashIndex;
       hashIndex%=SIZE;
    }

    dataList[hashIndex] = item;

}

struct DataItem* Search(int key){
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex]!=NULL){
    ///match the key
       if(dataList[hashIndex]->key == key)
       return dataList[hashIndex];

       ///match for the next , go to next cell
       ++hashIndex;

       ///confirm the index within List
       hashIndex%=SIZE;

    }

    return NULL;
}

struct DataItem *del(struct DataItem *item){

     int key = item->key;

     int hashIndex = getHashCode(key);

     while(dataList[hashIndex]!=NULL){

      if(dataList[hashIndex]->key == key){
         struct DataItem *temp = dataList[hashIndex];

         ///assign a dummy position
         dataList[hashIndex] = singleItem;
         return temp;

         }

         ///go to next cell
         ++hashIndex;

         hashIndex%=SIZE;
     }

     return NULL;


}

void display(){
int i=0;
     for(i=0;i<SIZE;i++){
        if(dataList[i]!=NULL)
        printf("(%d is key for data %d)",dataList[i]->key,dataList[i]->data);

        else printf("----");
     }

     printf("\n");
}

int main(){

   singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));

   singleItem->data = -1;
   singleItem->key = -1;

   Insert(1,20);
   Insert(21,40);
   Insert(2,30);
   Insert(22,60);
   Insert(4,25);
   Insert(12,44);
   Insert(14,32);
   Insert(17,11);
   Insert(13,78);
   Insert(37,97);

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
      printf("After deleting element\n");


   if(item!=NULL){
      printf("Element found : key = %d, data = %d\n",item->key,item->data);
   }
   else
   printf("Element not found\n");


  return 0;
}
