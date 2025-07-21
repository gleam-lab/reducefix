#include <bits/stdc++.h>
using namespace std;

struct Point {
    int coord, idx;
};

bool compare(const Point &a, const Point &b) {
    return a.coord < b.coord;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].coord;
        points[i].idx = i;
    }

    sort(points.begin(), points.end(), compare);

    for (int qi = 0; qi < q; ++qi) {
        int b, k;
        cin >> b >> k;
        
        vector<pair<int, int>> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = {abs(points[i].coord - b), points[i].idx};
        }

        sort(distances.begin(), distances.end());

        cout << distances[k - 1].first << '\n';
    }

    return 0;
}