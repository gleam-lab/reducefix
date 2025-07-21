#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3 + 5;

int n, m;
int row[MAX_N], col[MAX_N], up[MAX_N], down[MAX_N];
bool occupied[MAX_N][MAX_N];

int main() {
    scanf("%d %d", &n, &m);
    set<int> unique_rows, unique_cols, unique_up, unique_down;
    
    for(int i = 1; i <= m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        row[i] = y; col[i] = x; up[i] = y - x; down[i] = x + y;
        
        unique_rows.insert(y);
        unique_cols.insert(x);
        unique_up.insert(y - x);
        unique_down.insert(x + y);
        
        occupied[x][y] = true;
    }
    
    int total_empty = n * n;
    
    // Subtract the number of pieces that occupy rows, columns, diagonals
    total_empty -= unique_rows.size();
    total_empty -= unique_cols.size();
    total_empty -= unique_up.size();
    total_empty -= unique_down.size();
    
    // Add back the intersections (since they were subtracted twice)
    for(int i = 1; i <= m; ++i) {
        for(int j = i + 1; j <= m; ++j) {
            if((row[i] == row[j] || col[i] == col[j]) ||
               (up[i] == up[j] || down[i] == down[j])) {
                total_empty++;
            }
        }
    }
    
    printf("%d\n", total_empty);
    return 0;
}