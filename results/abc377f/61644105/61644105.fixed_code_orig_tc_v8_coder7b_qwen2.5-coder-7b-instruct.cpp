#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m;

struct Point {
    ll x, y;
};

bool cmp(const Point& a, const Point& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    cin >> n >> m;
    vector<Point> points(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end(), cmp);

    vector<ll> xs, ys;
    for (const auto& p : points) {
        xs.push_back(p.x);
        ys.push_back(p.y);
    }

    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    ll x_size = xs.size();
    ll y_size = ys.size();

    ll ans = n * n - m;
    for (int i = 0; i < m; ++i) {
        int x_idx = lower_bound(xs.begin(), xs.end(), points[i].x) - xs.begin();
        int y_idx = lower_bound(ys.begin(), ys.end(), points[i].y) - ys.begin();
        
        ans -= (x_size - x_idx) * (y_size - y_idx);
        ans -= x_idx * (y_size - y_idx);
        ans -= (x_size - x_idx) * y_idx;
        ans += x_idx * y_idx;
    }

    cout << ans << endl;
    return 0;
}