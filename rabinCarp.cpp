#include<iostream>
using namespace std;

int find_pattern(string,string);
int hash_function(string);
int main(){
    string text="bbbatifol aaa todful";
    string pattern="ful";
    if(find_pattern(text,pattern)!=-1){
        cout<<"Found at index : "<<find_pattern(text,pattern);
    }
    else{
        cout<<"Not found";
    }
    return 0;
}
int find_pattern(string text,string pattern){
    int pattern_code=hash_function(pattern);
    int first_group_code=hash_function(text.substr(0,3));
    if(pattern_code==first_group_code){
        return 0;
    }
    int code=first_group_code;
    int current_code;
    for(int i=1;i<text.size()-pattern.size()+1;i++){
        current_code=code-text[i-1]+text[i+2];
        if(current_code==pattern_code){
            if(pattern.compare(text.substr(i,3))==0){
                return i;
            }  
        }
        code=current_code;
    }
    return -1;
}
int hash_function(string word){
    int sum=0;
    for(int i=0;i<word.size();i++){
        sum+=(int)word[i];
    }
    return sum;
}
