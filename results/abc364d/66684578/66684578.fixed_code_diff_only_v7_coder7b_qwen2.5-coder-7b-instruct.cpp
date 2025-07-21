#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
const int MAXQ = 1e5 + 7;
const int INF = 1e9 + 7;

int a[MAXN], b[MAXQ];
vector<pair<int, int>> sorted_dists[MAXQ];

void preprocess() {
    for (int j = 0; j < MAXQ; ++j) {
        sorted_dists[j].clear();
        for (int i = 0; i < MAXN; ++i) {
            int dist = abs(a[i] - b[j]);
            sorted_dists[j].push_back({dist, i});
        }
        sort(sorted_dists[j].begin(), sorted_dists[j].end());
    }
}

int query(int j, int k) {
    return sorted_dists[j][k - 1].first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    preprocess();

    for (int j = 0; j < q; ++j) {
        cin >> b[j];
        int k; cin >> k;
        cout << query(j, k) << '\n';
    }

    return 0;
}