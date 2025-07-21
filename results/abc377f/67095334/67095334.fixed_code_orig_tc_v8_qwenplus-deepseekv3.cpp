#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int total_safe = (N - rows.size()) * (N - cols.size());
    
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int count = max_i - min_i + 1;
        
        set<int> covered;
        for (auto r : rows) {
            if (d - r >= 1 && d - r <= N) {
                covered.insert(r);
            }
        }
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= N) {
                covered.insert(d - c);
            }
        }
        total_safe += (count - covered.size());
    }
    
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int count = max_i - min_i + 1;
        
        set<int> covered;
        for (auto r : rows) {
            if (r - d >= 1 && r - d <= N) {
                covered.insert(r);
            }
        }
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= N) {
                covered.insert(c + d);
            }
        }
        total_safe += (count - covered.size());
    }
    
    cout << total_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}