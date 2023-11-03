#include<iostream>
#include <string>
using namespace std;
int main ( )
{  
  string speech ;
  string speech_2 ;
  int count =0 ;
    getline ( cin , speech);
    speech_2 = speech ; 
    for (int i=0 ; i<= speech.size() ; i++)
     {
        if( speech.substr(i , 3) == "he " )
        {
            speech_2.insert( i+2+7*count ," or she");
            count ++ ;
        }
        if( speech.substr(i , 3) == "he." )
        {
            speech_2.insert( i+2+7*count ," or she");
            count ++ ;
        }
        if( speech.substr(i , 3) == "He " )
        {
            speech_2.insert( i+2+7*count ," or she");
            count ++ ;
        }
         if( speech.substr(i , 4) == "him " )
        {
            speech_2.insert( i+3+7*count ," or her");
            count ++ ;
        }
         if( speech.substr(i , 4) == "him." )
        {
            speech_2.insert( i+3+7*count ," or her");
            count ++ ;
        }
     }
    
     cout<< speech_2;
    
return 0;
}