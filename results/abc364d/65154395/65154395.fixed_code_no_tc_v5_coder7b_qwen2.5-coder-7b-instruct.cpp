#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> k;

void solve() {
    int n, q; 
    cin >> n >> q;
    
    a.resize(n + 1);
    b.resize(q + 1);
    k.resize(q + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
    }

    vector<vector<int>> dist(n + 1, vector<int>(q + 1, INT_MAX));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= q; ++j) {
            dist[i][j] = abs(a[i] - b[j]);
        }
    }

    for (int j = 1; j <= q; ++j) {
        sort(dist[j].begin(), dist[j].end());
    }

    for (int j = 1; j <= q; ++j) {
        cout << dist[j][k[j]] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1; // Uncomment this line if there are multiple test cases
    // cin >> t;
    while (t--) solve();
    
    return 0;
}