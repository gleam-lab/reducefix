#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    Point(ll x, ll y) : x(x), y(y) {}
};

bool can_place(int x, int y, const set<Point>& occupied) {
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (auto& move : moves) {
        int nx = x + move.first;
        int ny = y + move.second;
        if (nx >= 0 && nx < 1000 && ny >= 0 && ny < 1000 && !occupied.count(Point(nx, ny))) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    set<Point> occupied;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        occupied.insert(Point(x-1, y-1)); // Convert 1-based index to 0-based
    }

    int valid = 0;
    for (int x = 0; x < 1000; ++x) {
        for (int y = 0; y < 1000; ++y) {
            if (occupied.count(Point(x, y))) continue;
            if (can_place(x, y, occupied)) {
                valid++;
            }
        }
    }

    cout << valid << endl;
    return 0;
}