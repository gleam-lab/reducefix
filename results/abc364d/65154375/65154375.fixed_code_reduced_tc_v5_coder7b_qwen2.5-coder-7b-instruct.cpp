#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN], b[MAXN], k[MAXN];

void solve() {
    int n, q; cin >> n >> q;
    vector<int> coords(n);
    for(int i = 0; i < n; ++i) {
        cin >> coords[i];
    }
    sort(coords.begin(), coords.end());
    
    for(int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    for(int i = 0; i < q; ++i) {
        auto it = lower_bound(coords.begin(), coords.end(), b[i]);
        int pos = it - coords.begin();
        int dist = abs(b[i] - coords[pos]);
        if(pos > 0 && abs(b[i] - coords[pos - 1]) < dist) {
            dist = abs(b[i] - coords[pos - 1]);
        }
        if(k[i] > 1 && pos < n - 1 && abs(b[i] - coords[pos + 1]) < dist) {
            dist = abs(b[i] - coords[pos + 1]);
        }
        cout << dist << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}