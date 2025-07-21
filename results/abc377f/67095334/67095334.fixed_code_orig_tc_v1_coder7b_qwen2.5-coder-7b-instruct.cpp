#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

int qpowm(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)(r *= a) %= m;
        (a *= a) %= m, b >>= 1;
    }
    return r;
}

int qpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)r *= a;
        a *= a;
        b >>= 1;
    }
    return r;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    set<int>h, v, d1, d2; // d1 stores i+j=d (main diagonal), d2 stores i-j=d (anti-diagonal)
    
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        h.insert(x);
        v.insert(y);
        d1.insert(x + y);
        d2.insert(x - y);
    }

    // Calculate the total number of empty squares initially
    int total_empty_squares = n * n - (h.size() + v.size() + d1.size() + d2.size());
    
    // Iterate over each diagonal to correct the overcounting
    for (auto d : d1) {
        set<int>s; // Record already counted positions on this diagonal
        for (auto x : h) { // Find intersections with horizontal lines
            if (1 <= d - x && d - x <= n) {
                s.insert(x);
            }
        }
        
        for (auto y : v) { // Find intersections with vertical lines
            if (1 <= d - y && d - y <= n) {
                s.insert(d - y);
            }
        }
        
        int len = 0;
        if (d <= n + 1) { // Left upper part, columns 1 to d-1
            len = d - 1;
        } else { // Right lower part, columns d-n to n
            len = n - (d - n) + 1;
        }
        total_empty_squares += len - s.size(); // Correct overcounting
    }

    for (auto d : d2) {
        set<int>s; // Record already counted positions on this diagonal
        for (auto x : h) { // Find intersections with horizontal lines
            if (1 <= x - d && x - d <= n) {
                s.insert(x);
            }
        }
        
        for (auto y : v) { // Find intersections with vertical lines
            if (1 <= d + y && d + y <= n) {
                s.insert(d + y);
            }
        }
        
        int len = 0;
        if (d <= 0) { // Right upper part, columns 1-d to n
            len = n - (1 - d) + 1;
        } else { // Left lower part, columns 1-n-d to n
            len = n - d;
        }
        total_empty_squares += len - s.size(); // Correct overcounting
    }

    cout << total_empty_squares << endl;
}

signed main() {
    int _ = 1;
    while (_) {
        solve();
    }
    return 0;
}