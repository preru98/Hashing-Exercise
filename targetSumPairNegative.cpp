/*
Problem :
    Find pairs which form target sum in an array
Solution : 
    Create hashtable of array.
    Traverse hashtable and store the index where valid element is found in serial fashion.
Constraints : 
    No duplicates 
    No 0s
*/

#include<iostream>
using namespace std;

int find_max_element(int[],int); 
int find_min_element(int[],int);
void generate_pairs(int[],int,int);
void display(int[],int);

int main(){

    int array[]={-1,3,18,2,9,-8,7,10,5};
    int size=sizeof(array)/sizeof(array[0]);
    int target_sum=10;
    generate_pairs(array,size,target_sum);

    return 0;
}

int find_max_element(int array[],int size){
    int a=INT32_MIN;
    for(int i=0;i<size;i++){
        if(array[i]>a){
            a=array[i];
        }
    }
    return a;
}

int find_min_element(int array[],int size){
    int a=INT32_MAX;
    for(int i=0;i<size;i++){
        if(array[i]<a){
            a=array[i];
        }
    }
    return a;
}

void generate_pairs(int array[],int size,int target_sum){
    int max=find_max_element(array,size);
    int min=find_min_element(array,size);
    int* hashtable=new int[max-min+1];
    int hashtable_size=max-min+1;
    for(int i=0;i<hashtable_size;i++){
        hashtable[i]=0;              //There cannot be any number which can be max+1
    }
    for(int i=0;i<size;i++){
        hashtable[array[i]-min]=array[i];
    }
    int count=0;
    for(int i=0;i<hashtable_size;i++){
        if(hashtable[i]!=0 && hashtable[target_sum-(i+min)-min]!=0){
            count++;
            cout<<count<<". ("<<hashtable[i]<<" , "<<hashtable[target_sum-(i+min)-min]<<")"<<endl;
            hashtable[i]=0;
        }
    }
    cout<<"Total pairs : "<<count;
}

void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
    }
}