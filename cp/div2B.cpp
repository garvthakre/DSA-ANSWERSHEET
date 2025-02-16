#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

   
    set<int> unique_elements;
    for (auto &[num, count] : freq) {
        if (count == 1) {
            unique_elements.insert(num);
        }
    }

  
    int max_length = 0, best_l = -1, best_r = -1;
    for (int l = 0, r = 0; r < n; r++) {
        if (unique_elements.count(a[r]) == 0) {
            l = r + 1; 
        } else {
            int length = r - l + 1;
            if (length > max_length) {
                max_length = length;
                best_l = l;
                best_r = r;
            }
        }
    }

  
    int original_score = n - freq.size();

    if (max_length == 0) {
        
        cout << "0\n";
    } else {
        cout << best_l + 1 << " " << best_r + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    
    return 0;
}