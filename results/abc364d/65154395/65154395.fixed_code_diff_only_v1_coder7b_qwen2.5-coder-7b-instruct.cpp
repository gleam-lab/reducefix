#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> distances(n);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        distances[i] = abs(x);
    }

    sort(distances.begin(), distances.end());

    for(int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        int dist = distances[k - 1];
        cout << dist << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}