#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

struct Point {
    ll coord;
    int index;
};

bool comparePoints(const Point& a, const Point& b) {
    return a.coord < b.coord;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Point> pointsA(n);
    for (int i = 0; i < n; ++i) {
        cin >> pointsA[i].coord;
        pointsA[i].index = i + 1;
    }

    sort(pointsA.begin(), pointsA.end(), comparePoints);

    vector<pair<ll, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<ll> results(q);
    multiset<ll> distances;

    for (int i = 0; i < q; ++i) {
        int targetIndex = queries[i].second - 1;
        ll targetCoord = queries[i].first;

        auto it = lower_bound(pointsA.begin(), pointsA.end(), Point{targetCoord, -1}, comparePoints);
        int idx = it - pointsA.begin();

        if (idx > 0) {
            distances.insert(abs(targetCoord - pointsA[idx - 1].coord));
        }
        if (idx < n) {
            distances.insert(abs(targetCoord - pointsA[idx].coord));
        }

        while ((int)distances.size() > targetIndex + 1) {
            distances.erase(distances.begin());
        }

        results[i] = *distances.begin();
    }

    for (const auto& result : results) {
        cout << result << '\n';
    }

    return 0;
}