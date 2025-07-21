#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const int MAXN = 1e5 + 5;

struct Compare {
    bool operator()(pi a, pi b) const {
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(q);
    vector<vector<pi>> dist(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dist[i].resize(q);
    }

    for (int i = 0; i < q; ++i) {
        cin >> b[i];
        for (int j = 0; j < n; ++j) {
            dist[j][i] = {abs(a[j] - b[i]), j};
        }
    }

    for (auto &v : dist) {
        sort(v.begin(), v.end());
    }

    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        cout << dist[k - 1][i].first << '\n';
    }

    return 0;
}