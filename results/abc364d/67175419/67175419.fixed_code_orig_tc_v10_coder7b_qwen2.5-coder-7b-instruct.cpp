#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int N, Q, a[MAXN], b[MAXN], k[MAXN];

struct Point {
    int idx, dist;
};

bool compare(const Point &p1, const Point &p2) {
    return p1.dist > p2.dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> Q;
    for(int i = 1; i <= N; ++i) cin >> a[i];
    sort(a + 1, a + N + 1);

    vector<vector<Point>> distances(Q);
    for(int j = 1; j <= Q; ++j) {
        cin >> b[j] >> k[j];
        for(int i = 1; i <= N; ++i) {
            distances[j].push_back({i, abs(b[j] - a[i])});
        }
        sort(distances[j].begin(), distances[j].end(), compare);
    }

    for(int j = 1; j <= Q; ++j) {
        cout << distances[j][k[j] - 1].dist << '\n';
    }

    return 0;
}