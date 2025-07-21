#include<bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
bool grid[MAXN][MAXN];

int main(){
    int H, W, Q;
    scanf("%d%d%d", &H, &W, &Q);

    memset(grid, true, sizeof(grid));

    while(Q--){
        int R, C;
        scanf("%d%d", &R, &C);
        R--, C--;

        if(grid[R][C]){
            grid[R][C] = false;
        } else {
            for(int i=R-1; i>=0 && grid[i][C]; i--) grid[i][C] = false;
            for(int i=R+1; i<H && grid[i][C]; i++) grid[i][C] = false;
            for(int j=C-1; j>=0 && grid[R][j]; j--) grid[R][j] = false;
            for(int j=C+1; j<W && grid[R][j]; j++) grid[R][j] = false;
        }
    }

    int count = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(grid[i][j]) count++;
        }
    }

    printf("%d\n", count);

    return 0;
}