#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 20

struct movie{
   //string name;
   char name[10];
   int year;
   double rating;
};

struct DataItem{
    struct movie m;
    int key;
};

struct DataItem *dataList[SIZE][SIZE];
struct DataItem *singleItem;
struct DataItem *item;

int getHashCode(int key){
    ///get the hash
    return key%SIZE;
}


void Insert(int key,char name[],int year,double rating){
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));

    //item->m.name = name;
    strcpy(item->m.name,name);
    item->m.year = year;
    item->m.rating = rating;
    item->key = key;

    ///get the hash

    int hashIndex = getHashCode(key);


    int k = 0;

    ///move  index untill find an empty
    while(dataList[hashIndex][k]!=NULL)
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
         ///++hashIndex

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
        printf("(%d is key for data: name= %s, year = %d,rating = %lf )",dataList[i][j]->key,dataList[i][j]->m.name,dataList[i][j]->m.year,dataList[i][j]->m.rating);

        else printf("~~");
        }
     }

     printf("\n");
}

int main(){

   singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));

   //singleItem->m = -1;
   singleItem->key = -1;

  Insert(1,"Forest Gump",1990,9.3);
  Insert(21,"Inception",2008,9.1);
   Insert(2,"Annabel",2000,6.2);
   Insert(22,"Shutter Island",2014,9.0);
//   Insert(4,25);
//   Insert(12,44);
//   Insert(14,32);
//   Insert(17,11);
//   Insert(13,78);
//   Insert(37,97);

   display();

   item = Search(21);


   if(item!=NULL){
      printf("Element found : key = %d, data: name= %s, year = %d,rating = %lf\n",item->key,item->m.name,item->m.year,item->m.rating);

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
   printf("\nAfter Deleting the element\n :");

   if(item!=NULL){
      printf("Element found : key = %d, data: name= %s, year = %d,rating = %lf\n",item->key,item->key,item->m.name,item->m.year,item->m.rating);
   }
   else
   printf("Element not found\n");


  return 0;
}


