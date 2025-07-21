#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Point {
    long long x, y;
    Point(long long x, long long y) : x(x), y(y) {}
};

int main() {
    long long n, m;
    cin >> n >> m;
    vector<Point> pieces(m);
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = Point(a - 1, b - 1);  // Convert to 0-indexed
    }

    set<pair<long long, long long>> occupied;
    for (const auto& p : pieces) {
        occupied.insert({p.x, p.y});
        // Check the capture area of the piece
        int captured[8][2] = {
            {p.x + 2, p.y + 1}, {p.x + 1, p.y + 2}, {p.x - 1, p.y + 2}, {p.x - 2, p.y + 1},
            {p.x - 2, p.y - 1}, {p.x - 1, p.y - 2}, {p.x + 1, p.y - 2}, {p.x + 2, p.y - 1}
        };
        for (int i = 0; i < 8; ++i) {
            auto [x, y] = captured[i];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                occupied.insert({x, y});
            }
        }
    }

    // Calculate the number of empty squares
    long long total_squares = n * n;
    long long occupied_squares = occupied.size();
    cout << total_squares - occupied_squares << endl;

    return 0;
}