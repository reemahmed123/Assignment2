#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string sentence;
    cout<<"please enter the sentence : ";
    getline(cin,sentence);
    for(int i=0;i<sentence.size();i++){
        if(i==0){
            sentence[i]=toupper(sentence[i]);
        }
        else{
            sentence[i]=tolower(sentence[i]);
        }
        if(sentence[i]==' '){
            if(sentence[i-1]==' '){

            continue;
        }
        }
        cout<<sentence[i];
    }
}