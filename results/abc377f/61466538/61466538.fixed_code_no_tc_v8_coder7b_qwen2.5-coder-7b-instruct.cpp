#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005;

bool inBounds(int a, int n) {
    return 1 <= a && a <= n;
}

// F - Avoid Queen Attack
void solve() {
    int n, m; 
    cin >> n >> m;
    unordered_set<int> row, col, d1, d2;
    for(int i = 0; i < m; ++i) {
        int a, b; 
        cin >> a >> b;
        row.insert(a);
        col.insert(b);
        d1.insert(a - b);
        d2.insert(a + b);
    }
    long long ans = 1LL * n * n;
    ans -= 1LL * row.size() * n;
    ans -= 1LL * col.size() * n;
    ans += 1LL * row.size() * col.size();

    for(int d : d1) {
        unordered_set<pair<int, int>> com;
        for(int r : row) {
            int c = r - d;
            if(inBounds(c, n)) com.insert({r, c});
        }
        for(int c : col) {
            int r = c + d;
            if(inBounds(r, n)) com.insert({r, c});
        }
        long long cnt = n - abs(d);
        ans -= cnt;
        ans += com.size();
    }

    for(int d : d2) {
        unordered_set<pair<int, int>> com;
        for(int r : row) {
            int c = d - r;
            if(inBounds(c, n)) com.insert({r, c});
        }
        for(int c : col) {
            int r = d - c;
            if(inBounds(r, n)) com.insert({r, c});
        }
        for(int od : d1) {
            int x = (d % 2) ^ (od % 2);
            if(x) continue;
            int r = (d + od) / 2;
            int c = (d - od) / 2;
            if(inBounds(r, n) && inBounds(c, n)) com.insert({r, c});
        }
        long long cnt = d < n ? (d - 1) : (2 * n - d);
        ans -= cnt;
        ans += com.size();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}