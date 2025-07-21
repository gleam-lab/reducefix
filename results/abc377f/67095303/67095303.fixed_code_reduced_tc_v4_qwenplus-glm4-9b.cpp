#include<bits/stdc++.h>
#define int long long

using namespace std;

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Initialize the answer with all possible empty squares
    int ans = n * n - m;

    // For each piece, calculate the number of squares it blocks
    for (int i = 0; i < m; ++i) {
        int x = pieces[i].first;
        int y = pieces[i].second;

        // Check blocks in row x
        bool row_block = find(pieces.begin(), pieces.end(), make_pair(x, y)) != pieces.end();
        // Check blocks in column y
        bool col_block = find(pieces.begin(), pieces.end(), make_pair(y, x)) != pieces.end();
        // Check blocks in diagonal x+y
        bool diag1_block = (x + y) * 2 - 1 <= n && find(pieces.begin(), pieces.end(), make_pair(x + y, y - x)) != pieces.end();
        // Check blocks in diagonal x-y
        bool diag2_block = (x - y) * 2 - 1 <= n && find(pieces.begin(), pieces.end(), make_pair(x - y, y + x)) != pieces.end();

        // Subtract the number of blocked squares due to the current piece
        if (row_block) ans -= (n - max(0, y - 2));
        if (col_block) ans -= (n - max(0, x - 2));
        if (diag1_block) ans -= (n - max(0, y - 2));
        if (diag2_block) ans -= (n - max(0, x - 2));
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}