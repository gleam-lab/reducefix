#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_H = 1000, MAX_W = 1000, MAX_Y = 100000;
ll H, W, Y;
ll A[MAX_H][MAX_W];
ll ans[MAX_Y + 1];

struct Point {
    ll x, y;
    Point(ll x, ll y) : x(x), y(y) {}
    bool operator<(const Point& other) const {
        return A[x][y] < A[other.x][other.y];
    }
};

int main() {
    cin >> H >> W >> Y;
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<Point> points;
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || A[i][j] <= 0) {
                ans[0] -= A[i][j];
            } else {
                points.emplace_back(i, j);
            }
        }
    }

    sort(points.begin(), points.end());

    for (ll year = 1; year <= Y; ++year) {
        ll currentYear = year;
        for (auto& point : points) {
            if (A[point.x][point.y] <= currentYear) {
                ans[year] -= A[point.x][point.y];
                currentYear = max(currentYear, A[point.x][point.y]);
            } else {
                break;
            }
        }
    }

    for (ll i = 1; i <= Y; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}