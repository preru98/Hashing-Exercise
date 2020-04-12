/*
Problem :
    Find whether an array is subset of another array.
Solution : 
    Array A : Superset
    Array B : Subset
    Create hashtable of array A.
    Traverse second array, B and search every item in A.
    If every element is found, then YES, NO otherwise.
Constraints :
    Elements Range    : 1-50 [Inclusive]
    Max Size of Array : 15   
    Duplicates
*/ 

#include<iostream>
using namespace std;

const int size_hashtable=51;
int hashtable[size_hashtable];

void build_hashtable(int[],int);
bool check_subset(int[],int);

int main(){
    int superset[]={1,4,6,34,34,2,48,21};
    int subset[]={4,48,34,34};
    int size_superset=sizeof(superset)/sizeof(superset[0]);
    int size_subset=sizeof(subset)/sizeof(subset[0]);
    
    build_hashtable(superset, size_superset);
    cout<<check_subset(subset, size_subset);

    return 0;
}

void build_hashtable(int superset[],int size_superset){
    for(int i=0;i<size_superset;i++){
        hashtable[i]=0;
    }
    for(int i=0;i<size_superset;i++){
        hashtable[superset[i]]++;
    }
}

bool check_subset(int subset[],int size_subset){
    for(int i=0;i<size_subset;i++){
        if(hashtable[subset[i]]<1){
            return false;
        }
        hashtable[subset[i]]--;
    }
    return true;
}
