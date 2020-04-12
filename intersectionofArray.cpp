/*
Problem :
    Given two arrays size m and size n, find intersection of them. 
Solution : 
    Create single hashtable for both arrays.
    Traverse second array hashtable and store the index where valid element is found in serial fashion and store them in an array.
Constraints : 
    No duplicates  
    No negative numbers, 0 allowed
*/

#include<iostream>
using namespace std;

int find_max_element(int[],int); 
void get_intersection(int[],int,int[],int);
void display(int[],int);

int main(){
    int array1[]={1,5,3,7,6,9,10};
    int array2[]={3,7,6,4};
    int size1=sizeof(array1)/sizeof(array1[0]);
    int size2=sizeof(array2)/sizeof(array2[0]);
    
    cout<<"\nArray 1        : ";
    display(array1,size1);
    cout<<"\n";

    cout<<"\nArray 2        : ";
    display(array2,size2);
    cout<<"\n";

    cout<<"\nIntersection   : ";
    get_intersection(array1,size1,array2,size2);
    
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

void get_intersection(int array1[],int size1, int array2[],int size2){

    const int size_resultant_array=size1+size2;
    int *resultant_array=new int[size_resultant_array];   

    int max=find_max_element(array1,size1);
    int max2=find_max_element(array2,size2);
    if(max<max2){
        max=max2;
    }

    const int size_hashtable=max+1;
    int *hashtable=new int[size_hashtable];
    
    for(int i=0;i<size_hashtable;i++){
        hashtable[i]=-1;
    }
    int i;
    for(i=0;i<size1 && i<size2;i++){
        hashtable[array1[i]]++;
        hashtable[array2[i]]++;
    }
    if(i==size1){ 
        while(i<size2){
            hashtable[array2[i]]++;
            i++;
        }
    }
    if(i==size2){   
        while(i<size1){
            hashtable[array1[i]]++;
            i++;
        }
    }
    int count=0;
    for(int j=0;j<size_hashtable;j++){
        if(hashtable[j]>0){
            resultant_array[count]=j;
            count++;
        }
    }
    display(resultant_array,count);
}

void display(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
    }
}