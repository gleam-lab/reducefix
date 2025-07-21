#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<int> occupied_rows(n + 1, 0);
    vector<int> occupied_cols(n + 1, 0);
    vector<int> occupied_d1(2 * n + 1, 0);
    vector<int> occupied_d2(2 * n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a++; // Convert to 1-based index
        b++; // Convert to 1-based index

        occupied_rows[a]++;
        occupied_cols[b]++;
        occupied_d1[a + b]++;
        occupied_d2[a - b]++;
    }

    int free_squares = n * n;

    // Subtract occupied rows and columns
    for (int i = 1; i <= n; i++) {
        free_squares -= occupied_rows[i];
        free_squares -= occupied_cols[i];
    }

    // Subtract occupied diagonals d1 = i + j and d2 = i - j
    for (int d = 1; d <= 2 * n; d++) {
        free_squares -= occupied_d1[d];
        free_squares -= occupied_d2[d];
    }

    cout << free_squares << endl;

    return 0;
}