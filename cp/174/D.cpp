#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200005

 
int freq[MAXN][26];

int mnt(int a, int b) {
    return a < b ? a : b;
}

 
int fre(int l, int r, int c) {
    return freq[r+1][c] - freq[l][c];
}

int main(){
    int t;
    if(scanf("%d", &t) != 1)
        return 1;
    char s[MAXN];
    while(t--){
        if(scanf("%s", s) != 1)
            return 1;
        int n = (int)strlen(s);
        
        // Build the prefix frequency array.
        // freq[0] is all zeros.
        for (int c = 0; c < 26; c++){
            freq[0][c] = 0;
        }
        for (int i = 0; i < n; i++){
            for (int c = 0; c < 26; c++){
                freq[i+1][c] = freq[i][c];
            }
            freq[i+1][ s[i]-'a' ]++;
        }
        
        // If the string is already a palindrome, answer is 0.
        int pal = 1;
        for (int i = 0; i < n/2; i++){
            if(s[i] != s[n-1-i]){
                pal = 0;
                break;
            }
        }
        if(pal){
            printf("0\n");
            continue;
        }
        
        
        int half = n/2;
        int *p = (int*)malloc((half+1)*sizeof(int));
        p[0] = 0;
        for (int i = 0; i < half; i++){
            int d = (s[i] == s[n-1-i]) ? 1 : 0;
            p[i+1] = p[i] + d;
        }
        
        
        
        int lo = 1, hi = n, ans = n;
        while(lo <= hi){
            int mid = (lo + hi) / 2; // candidate length for T
            int validK = 0;
            // Try every possible T = [L, R] of length mid.
            for (int L = 0; L <= n - mid; L++){
                int R = L + mid - 1;
                // Fixed parts: prefix [0,L-1] and suffix [R+1,n-1].
                // For indices fixed on both ends, we need s[i]==s[n-1-i].
                int m = mnt(L, n - R - 1);
                if(m > 0 && p[m] != m)
                    continue;
                    
             
                int F[26] = {0}; // forced frequency counts
                int plow = n - 1 - R;
                int pigh = L - 1;
                if(L > 0 && plow <= pigh){
                    // Also ensure i <= n-1-L.
                    int limit = n - 1 - L;
                    if(pigh > limit)
                        pigh = limit;
                    if(plow < 0)
                        plow = 0;
                    if(plow <= pigh){
                        for (int c = 0; c < 26; c++){
                            F[c] += fre(plow, pigh, c);
                        }
                    }
                }
                
                int suflo = R + 1;
                int sigh = n - 1 - L;
                if(R < n - 1 && suflo <= n - 1 && suflo <= sigh){
                    int lwb = n - 1 - R;
                    if(suflo < lwb)
                        suflo = lwb;
                    if(suflo <= sigh){
                        for (int c = 0; c < 26; c++){
                            F[c] += fre(suflo, sigh, c);
                        }
                    }
                }
                
                // Now, letters available in T.
                int avail[26];
                for (int c = 0; c < 26; c++){
                    avail[c] = fre(L, R, c);
                }
                
                // Check that for every letter c:
                // avail[c] >= forced count F[c] and (avail[c]-F[c]) is even.
                int okForced = 1;
                for (int c = 0; c < 26; c++){
                    if(avail[c] < F[c] || ((avail[c] - F[c]) & 1)){
                        okForced = 0;
                        break;
                    }
                }
                if(okForced){
                    validK = 1;
                    break;
                }
            }
            if(validK){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        printf("%d\n", ans);
        free(p);
    }
    return 0;
}