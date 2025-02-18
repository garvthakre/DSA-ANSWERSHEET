#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 1;
    
    while(t--){
        int n, m;
        if(scanf("%d %d", &n, &m) != 2)
            return 1;
        int total = n * m;
        
        
        int *grid = (int*) malloc(total * sizeof(int));
        for (int i = 0; i < total; i++){
            scanf("%d", &grid[i]);
        }
        
         
        int size = total + 1; // colors: 1..total
        int *colco = (int*) calloc(size, sizeof(int));
        char *pres = (char*) calloc(size, sizeof(char));
        
        for (int i = 0; i < total; i++){
            int c = grid[i];
            if(!pres[c]){
                pres[c] = 1;
                colco[c] = 1; // assume isolated for now
            }
        }
        
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int idx = i * m + j;
                int c = grid[idx];
                if(j + 1 < m) { // right neighbor
                    if(grid[idx + 1] == c)
                        colco[c] = 2;
                }
                if(i + 1 < n) { // bottom neighbor
                    int idx2 = (i + 1) * m + j;
                    if(grid[idx2] == c)
                        colco[c] = 2;
                }
            }
        }
        
        
        long long S = 0;
        int bt = 0;
        for (int c = 1; c < size; c++){
            if(pres[c]){
                S += colco[c];
                if(colco[c] > bt)
                    bt = colco[c];
            }
        }
        
       
        int ans = (int)(S - bt);
        printf("%d\n", ans);
        
        free(grid);
        free(colco);
        free(pres);
    }
    return 0;
}