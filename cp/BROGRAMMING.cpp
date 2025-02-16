#include<iostream>
#include<string>
using namespace std;
int main(){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     int p;
     cin>>p;
     while(p--){
          int m;
          cin>>m;
          string s;
          cin>>s;
          int mov =0;
           for(int i=1;i<m;i++){
          if(s[i]!=s[i-1])
          mov++;
           }
          if(s[0]=='1')
               mov++;
               cout<<mov<<"\n";
               
           }
           return 0;
     }
