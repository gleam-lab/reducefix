#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

using LL = long long;

int n, m;
vector<pair<int, int>> points;

bool isCapture(int x, int y, int px, int py) {
    // Check if (x, y) can be captured by (px, py)
    return (x == px || y == py) || 
           (x + y == px + py) || 
           (x - y == px - py);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    points.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    set<pair<int, int>> reachable;
    for (auto& p : points) {
        reachable.insert(p);
        reachable.insert({p.first, n - p.second + 1});
        reachable.insert({n - p.first + 1, p.second});
        reachable.insert({p.first - p.second + n + 1, p.second});
        reachable.insert({p.first + p.second + 1, p.second});
    }

    int freeSquares = n * n - m;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            bool canPlace = true;
            for (auto& p : points) {
                if (isCapture(x, y, p.first, p.second)) {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace) {
                if (reachable.find({x, y}) == reachable.end()) {
                    freeSquares++;
                }
            }
        }
    }

    cout << freeSquares << endl;
    return 0;
}