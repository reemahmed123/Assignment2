#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
using namespace std;
void sieve_of_Eratosthenes(int upper_limit){  
    bool prime[upper_limit];   
    for(int i=2;i<=upper_limit;i++){
        prime[i]=1;
    }
    for(int i=2;i<=upper_limit;i++){
        if(prime[i]){
        for(int j=i*i;j<=upper_limit;j+=i){
            prime[j]=0;
        }
        }
    }
    for(int i=2;i<=upper_limit;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
}
int main(){
    cout<<"Enter the upper limit you want to generate a prime series: "<<endl;
    int upper_limit;
    cin>>upper_limit;
    sieve_of_Eratosthenes(upper_limit);
}