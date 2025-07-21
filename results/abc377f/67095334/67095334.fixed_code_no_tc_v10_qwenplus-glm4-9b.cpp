#include<bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    
    vector<int> rows(n+1, 0), cols(n+1, 0);
    vector<pair<int, int>> diag1, diag2;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        rows[x]++;
        cols[y]++;
        diag1.emplace_back(x+y, i); // diagonal (i+j)
        diag2.emplace_back(x-y, i); // diagonal (i-j)
    }
    
    set<pair<int, int>> unique_diag1, unique_diag2;
    for (auto &d : diag1) {
        unique_diag1.insert(d);
    }
    for (auto &d : diag2) {
        unique_diag2.insert(d);
    }
    
    int free_rows = n - rows[1];
    int free_cols = n - cols[1];
    int free_squares = n * n - m;
    
    // Subtract rows and columns that are fully occupied
    for (int i = 2; i <= n; i++) {
        if (rows[i] == n) free_rows--;
        if (cols[i] == n) free_cols--;
    }
    
    // Subtract squares on diagonals that are fully occupied
    int free_diag1 = n + 1;
    int free_diag2 = n + 1;
    for (auto &d : unique_diag1) {
        int r = d.first;
        if (r > 0 && r <= n) {
            int free_in_diag1 = n - gcd(r, n);
            free_diag1 = min(free_diag1, free_in_diag1);
        }
    }
    for (auto &d : unique_diag2) {
        int r = d.first;
        if (r > 0 && r <= n) {
            int free_in_diag2 = n - gcd(r, n);
            free_diag2 = min(free_diag2, free_in_diag2);
        }
    }
    
    // Calculate the answer
    int ans = free_squares - free_rows - free_cols + free_diag1 + free_diag2;
    cout << ans << endl;
    
    return 0;
}