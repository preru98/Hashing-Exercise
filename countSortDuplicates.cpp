/*
Problem :
    Perform countsort
    Duplicates Allowed
    0 allowed
Solution : 
    Create hashtable of array.
    Traverse hashtable and store the index where valid element is found in serial fashion.
Constraints : 
    No negative numbers
*/

#include<iostream>
using namespace std;

int find_max_element(int[],int); 
void count_sort(int[],int);
void display(int[],int);

int main(){
    int array[]={8,0,9,4,5,8,1,9,2,1,3,9,0};
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
            while(hashtable[i]!=-1){
                array[j]=i;
                j++;
                hashtable[i]--;
            }
        }
    }
}

void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
    }
}