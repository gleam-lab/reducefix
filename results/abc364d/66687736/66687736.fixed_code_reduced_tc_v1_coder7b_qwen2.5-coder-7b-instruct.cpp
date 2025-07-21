#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, idx;
};

bool cmp(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x;
        points[i].idx = i;
    }

    vector<ll> queries(q);
    vector<int> ks(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i] >> ks[i];
        --ks[i]; // Adjusting to zero-based index
    }

    sort(points.begin(), points.end());

    vector<vector<ll>> dists(n);
    for (int i = 0; i < n; ++i) {
        dists[i].resize(n);
        for (int j = 0; j < n; ++j) {
            dists[i][j] = abs(points[i].x - points[j].x);
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(dists[i].begin(), dists[i].end());
    }

    for (int i = 0; i < q; ++i) {
        int target = queries[i];
        int k = ks[i];

        int left = 0, right = 1e9 + 10;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (dists[j][points[target].idx] <= mid) {
                    count += j + 1;
                } else {
                    break;
                }
            }
            if (count >= k + 1) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}