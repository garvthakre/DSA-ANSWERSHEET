#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 1;

    const int XP = 200000 + 5;
    long long *pow2 = (long long*)malloc(sizeof(long long) * XP);
    long long *invPow2 = (long long*)malloc(sizeof(long long) * XP);
    if (!pow2 || !invPow2) return 1;
    
    pow2[0] = 1;
    for (int i = 1; i < XP; i++) {
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
    }

    long long inv2 = 499122177;
    invPow2[0] = 1;
    for (int i = 1; i < XP; i++) {
        invPow2[i] = (invPow2[i - 1] * inv2) % MOD;
    }
    
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 1;
        
        int *a = (int*)malloc(sizeof(int) * n);
        if (!a) return 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        long long ans = 0;
        long long sm = 0;
        int ct = 0;
        int count2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                sm = (sm + invPow2[count2]) % MOD;
                ct++;
            } else if (a[i] == 2) {
                count2++;
            } else if (a[i] == 3) {
                long long cot = ((pow2[count2] * sm) % MOD - ct) % MOD;
                if (cot < 0) cot += MOD;
                ans = (ans + cot) % MOD;
            }
        }
        
        printf("%lld\n", ans);
        free(a);
    }
    
    free(pow2);
    free(invPow2);
    return 0;
}
