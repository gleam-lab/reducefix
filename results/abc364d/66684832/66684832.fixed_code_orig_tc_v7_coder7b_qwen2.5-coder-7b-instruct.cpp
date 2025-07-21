#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

struct Point {
    ll coord, idx;
};

bool compareX(const Point &a, const Point &b) {
    return a.coord < b.coord;
}

ll findKthClosest(vector<Point> &points, ll target, int k) {
    vector<ll> distances(points.size());
    for (int i = 0; i < points.size(); ++i) {
        distances[i] = abs(target - points[i].coord);
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<Point> points(n);
    for (ll i = 0; i < n; ++i) {
        points[i] = {a[i], i};
    }

    sort(points.begin(), points.end(), compareX);

    while (q--) {
        ll x, k;
        cin >> x >> k;
        --k; // Convert 1-based index to 0-based
        ll result = findKthClosest(points, x, k + 1); // k is 0-based in nth_element
        cout << result << '\n';
    }

    return 0;
}