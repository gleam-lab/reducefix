#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define bs bitset
#define eb emplace_back

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

struct Point {
    ll x, y, height;
    Point(ll x, ll y, ll height) : x(x), y(y), height(height) {}
    bool operator>(const Point& p) const {
        return height < p.height;
    }
};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vl A(h * w);
    rep(i, h) rep(j, w) cin >> A[i * w + j];

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    ll island_area = 0;

    // Initialize the priority queue with the first column and last column cells
    rep(i, h) {
        pq.eb(Point(i, 0, A[i * w]));
        pq.eb(Point(i, w - 1, A[i * w + w - 1]));
        island_area += max(0LL, A[i * w]);
        island_area += max(0LL, A[i * w + w - 1]);
    }

    // Initialize the priority queue with the first row and last row cells
    rep(j, w) {
        pq.eb(Point(0, j, A[j]));
        pq.eb(Point(h - 1, j, A[(h - 1) * w + j]));
        island_area += max(0LL, A[j]);
        island_area += max(0LL, A[(h - 1) * w + j]);
    }

    y--; // The loop will run one time more than the years needed, so we decrement it
    while (y--) {
        ll top_height = pq.top().height;
        pq.pop();
        island_area -= 1;

        for (ll k = 0; k < 4; ++k) {
            ll ni = pq.top().x + dx[k], nj = pq.top().y + dy[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && A[ni * w + nj] > top_height) {
                pq.push(Point(ni, nj, A[ni * w + nj]));
                island_area += 1;
            }
        }
    }

    rep(i, y + 1) cout << island_area << '\n';
    return 0;
}