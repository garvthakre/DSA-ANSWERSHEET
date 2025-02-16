#include <bits/stdc++.h>
using namespace std;
 

const int z = 1 << 30;
 

vector<pair<int,int>> mergeint(vector<pair<int,int>> intervals) {
    if(intervals.empty()) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<pair<int,int>> merged;
    pair<int,int> cur = intervals[0];
    for (size_t i = 1; i < intervals.size(); i++){
        if(intervals[i].first <= cur.second){
            cur.second = max(cur.second, intervals[i].second);
        } else {
            merged.push_back(cur);
            cur = intervals[i];
        }
    }
    merged.push_back(cur);
    return merged;
}
 

vector<pair<int,int>> split(int L, int R) {
    vector<pair<int,int>> blocks;
    while(L < R) {
        int step = (L == 0 ? 1 : L & -L);
        while((long long)step << 1 <= R - L)
            step <<= 1;
        while(L + step > R)
            step >>= 1;
        blocks.push_back({L, L + step});
        L += step;
    }
    return blocks;
}
 

vector<pair<int,int>> imgint(int c, int L, int R) {
    vector<pair<int,int>> blocks = split(L, R);
    vector<pair<int,int>> images;
    for(auto &b: blocks){
        int a = b.first, bEnd = b.second;
        int size = bEnd - a;  
        int k = 31 - __builtin_clz(size);
        int C = c >> k;       
        int newA = (a / size) ^ C;
        int blockStart = newA * size;
        int blockEnd = blockStart + size;
        images.push_back({blockStart, blockEnd});
    }
    return mergeint(images);
}
 

vector<pair<int,int>> compint(const vector<pair<int,int>> &intervals, int z) {
    vector<pair<int,int>> comp;
    int prev = 0;
    for(auto &iv: intervals) {
        if(prev < iv.first)
            comp.push_back({prev, iv.first});
        prev = max(prev, iv.second);
    }
    if(prev < z)
        comp.push_back({prev, z});
    return comp;
}
 

vector<pair<int,int>> getxor(int c, int L, int z) {
    vector<pair<int,int>> img = imgint(c, 0, L);
    vector<pair<int,int>> comp = compint(img, z);
    return mergeint(comp);
}
 

vector<pair<int,int>> sectvals(const vector<pair<int,int>> &A, const vector<pair<int,int>> &B) {
    vector<pair<int,int>> res;
    int i = 0, j = 0;
    while(i < (int)A.size() && j < (int)B.size()){
        int L = max(A[i].first, B[j].first);
        int R = min(A[i].second, B[j].second);
        if(L < R)
            res.push_back({L, R});
        if(A[i].second < B[j].second)
            i++;
        else
            j++;
    }
    return res;
}
 

bool inIntervals(const vector<pair<int,int>> &intervals, int x) {
    int lo = 0, hi = intervals.size()-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(intervals[mid].first <= x && x < intervals[mid].second)
            return true;
        else if(x < intervals[mid].first)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

void solveTestCase(){
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
   
    vector<int> S(n);
    for (int i = 0; i < n; i++){
        S[i] = A[n-1-i];
    }
   
    vector<int> T(n+1, 0);
    for (int i = 1; i <= n; i++){
        T[i] = T[i-1] ^ S[i-1];
    }
   
    vector< vector<pair<int,int>> > IIntervals(n);
    for (int i = 0; i < n; i++){
        IIntervals[i] = mergeint(getxor(T[i], S[i], z));
    }
    
    vector< vector<pair<int,int>> > JIntervals(n+1);
    JIntervals[0].push_back({0, z});
    int maxValid = 0;
    for (int k = 0; k < n; k++){
        vector<pair<int,int>> inter = sectvals(JIntervals[k], IIntervals[k]);
        inter = mergeint(inter);
        JIntervals[k+1] = inter;
        if(inter.empty()){
            maxValid = k; 
            for (int kk = k+1; kk <= n; kk++){
                JIntervals[kk].clear();
            }
            break;
        } else {
            maxValid = k+1;
        }
    }
   
    for (int i = 0; i < q; i++){
        int z; cin >> z;
        int lo = 0, hi = maxValid;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(!JIntervals[mid].empty() && inIntervals(JIntervals[mid], z))
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << lo << (i+1==q ? "\n" : " ");
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while(t--){
        solveTestCase();
    }
    return 0;
}