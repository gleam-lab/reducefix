#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> a[MAXN], b[MAXN];

void solve() {
    int n, q; cin >> n >> q;
    vector<pair<int, int>> dist(n * 2);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x].push_back(i + 1);
    }
    for(int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        b[x].push_back(k);
    }

    for(int i = 0; i < MAXN; ++i) {
        sort(a[i].begin(), a[i].end());
    }

    for(int i = 0; i < MAXN; ++i) {
        for(auto &x: a[i]) {
            dist[x].first = i;
            dist[x].second = abs(i - x);
        }
    }

    for(int i = 0; i < MAXN; ++i) {
        sort(dist.begin() + min(MAXN - 1, i + 1), dist.begin() + max(0, i - 1));
    }

    for(int i = 0; i < q; ++i) {
        int x = b[i].back(); b[i].pop_back();
        cout << dist[x][b[i].back()] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1; //cin >> T;
    while(T--) solve();
    return 0;
}