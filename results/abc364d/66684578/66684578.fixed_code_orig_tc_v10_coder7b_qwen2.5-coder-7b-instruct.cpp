#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18
#define MAXN 100005

vector<ll> dist[MAXN];

void preprocess(vector<vector<ll>>& points) {
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i].push_back(abs(points[i][0] - points[j][0]));
        }
        sort(dist[i].begin(), dist[i].end());
    }
}

ll query(int idx, int k) {
    return dist[idx][k - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<ll>> points(n + q, vector<ll>(2));
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0];
        points[n + i][0] = points[i][0];
    }

    for (int i = 0; i < q; ++i) {
        cin >> points[n + i][0] >> points[n + i][1];
    }

    preprocess(points);

    for (int i = n; i < n + q; ++i) {
        cout << query(i, points[i][1]) << '\n';
    }

    return 0;
}