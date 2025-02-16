#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Coin(vector<int>& a) {
    int n = a.size();
    vector<long long> pre(n + 1, 0);
    vector<long long> suf(n + 1, 0);
    
   
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + max(0, a[i]);
    }
    

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + max(0, -a[i]);
    }
    
    
    long long maxSum = 0;
    for (int i = 0; i <= n; i++) {
        maxSum = max(maxSum, pre[i] + suf[i]);
    }
    
    return maxSum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << Coin(a) << endl;
    }
    
    return 0;
}