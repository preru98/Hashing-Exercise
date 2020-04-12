/*
Problem :
    Perform countsort
Solution : 
    Create hashtable of array.
    Traverse hashtable and store the index where valid element is found in serial fashion.
Constraints : 
    No duplicates  
    No negative numbers, 0 allowed
*/

#include<iostream>
using namespace std;

int find_max_element(int[],int); 
void count_sort(int[],int);
void display(int[],int);

int main(){
    int array[]={15,21,34,0,3,18,30,45};
    int size=sizeof(array)/sizeof(array[0]);
    cout<<"\nBefore Sorting :\n";
    display(array,size);
    count_sort(array,size);
    cout<<"\nAfter Sorting :\n";
    display(array,size);
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

void count_sort(int array[],int size){

    int max=find_max_element(array,size);
    int *hashtable=new int[max+1];

    for(int i=0;i<max+1;i++){
        hashtable[i]=-1;
    }
    for(int i=0;i<size;i++){
        hashtable[array[i]]++;
    }
    for(int i=0,j=0;i<max+1;i++){
        if(hashtable[i]!=-1){
            array[j]=i;
            j++;
        }
    }
}

void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
    }
}