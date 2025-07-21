#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;
vector<vector<pair<int, int>>> distances;

void preprocess() {
    int n = a.size(), m = b.size();
    distances.resize(m);
    for (int i = 0; i < m; ++i) {
        distances[i].resize(n);
        for (int j = 0; j < n; ++j) {
            distances[i][j] = abs(a[j] - b[i]);
        }
        sort(distances[i].begin(), distances[i].end());
    }
}

int query(int idx, int k) {
    return distances[idx][k - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    a.resize(n), b.resize(q);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i] >> k[i];

    preprocess();

    for (int i = 0; i < q; ++i) {
        cout << query(i, k[i]) << '\n';
    }

    return 0;
}