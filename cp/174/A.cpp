#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool solve(vector<int>& b){
    int n=b.size();
    for(int i =0;i<n-2;i++){
        if(b[i]==1 && b[i+1]==0&&b[i+2]==1){
            return false;
        }
    }
    return true;
}
int main(){
    int t ;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n-2);
        for(int i =0;i<n-2;i++){
            cin>>b[i];
        }
        cout<<(solve(b)?"YES":"NO")<<endl;
    }
    return 0;
}