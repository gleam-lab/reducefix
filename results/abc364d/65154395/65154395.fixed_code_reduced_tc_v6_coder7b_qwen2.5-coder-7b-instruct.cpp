#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> a[MAXN];
int n, q;

void preprocess() {
    vector<int> dist;
    for (int i = 1; i <= n; ++i) {
        for (auto& b : a[i]) {
            dist.push_back(abs(b - i));
        }
        sort(dist.begin(), dist.end());
        a[i].clear();
        for (int j = 0; j < dist.size(); ++j) {
            a[i].push_back(dist[j]);
        }
        dist.clear();
    }
}

int query(int b, int k) {
    return a[b][k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[x].push_back(i);
    }

    preprocess();

    for (int i = 1; i <= q; ++i) {
        int b, k; cin >> b >> k;
        cout << query(b, k) << endl;
    }

    return 0;
}