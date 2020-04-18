/*
Problem :
    Perform countsort
    Negative numbers
Solution : 
    Create hashtable of array.
    Traverse hashtable and store the index where valid element is found in serial fashion.
Constraints : 
    No duplicates  
*/

#include<iostream>
using namespace std;

int find_max_element(int[],int); 
void count_sort(int[],int);
void display(int[],int);

int main(){
    int array[]={-3,0,1,3,-2,2};
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
int find_min_element(int array[],int size){
    int a=INT32_MAX;
    for(int i=0;i<size;i++){
        if(array[i]<a){
            a=array[i];
        }
    }
    return a;
}

void count_sort(int array[],int size){

    int max=find_max_element(array,size);
    int min=find_min_element(array,size);
    int size_hashtable=max-min+1;
    int *hashtable=new int[size_hashtable];

    for(int i=0;i<size_hashtable;i++){
        hashtable[i]=-1;
    }
    for(int i=0;i<size;i++){
        hashtable[array[i]-min]++;
    }
    for(int i=0,j=0;i<size_hashtable;i++){
        if(hashtable[i]!=-1){
            array[j]=i+min;
            j++;
        }
    }
}

void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
    }
}