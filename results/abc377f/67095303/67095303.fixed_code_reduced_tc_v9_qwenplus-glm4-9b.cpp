#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
set<pair<int, int>> horizontal;
set<pair<int, int>> vertical;
set<pair<int, int>> diagonal1; // i + j
set<pair<int, int>> diagonal2; // i - j

void process(const pair<int, int>& p) {
    // Process each piece
    int x = p.first;
    int y = p.second;

    // Update horizontal
    horizontal.insert({x, -1});
    horizontal.insert({x, n});

    // Update vertical
    vertical.insert({y, -1});
    vertical.insert({y, n});

    // Update diagonal1
    if (x + y <= n) {
        diagonal1.insert({x + y, -1});
        diagonal1.insert({x + y, n});
    }

    // Update diagonal2
    if (x - y >= 1) {
        diagonal2.insert({x - y, 1});
        diagonal2.insert({x - y, n - x + y});
    }
}

int count_empty_positions() {
    // Count empty positions
    int count = n * n;

    // Subtract taken positions
    count -= horizontal.size();
    count -= vertical.size();
    count -= diagonal1.size();
    count -= diagonal2.size();

    // Subtract intersections
    for (auto it = horizontal.begin(); it != horizontal.end(); ++it) {
        for (auto jt = vertical.begin(); jt != vertical.end(); ++jt) {
            pair<int, int> p1 = {it->first, jt->second};
            pair<int, int> p2 = {it->first, jt->first};
            if (p1.first + p1.second <= n) {
                diagonal1.erase({p1.first + p1.second, -1});
                diagonal1.erase({p1.first + p1.second, n});
            }
            if (p2.first + p2.second <= n) {
                diagonal2.erase({p2.first + p2.second, 1});
                diagonal2.erase({p2.first + p2.second, n - p2.first + p2.second});
            }
            count -= 1;
        }
    }

    return count;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        process({x, y});
    }
    cout << count_empty_positions() << "\n";
    return 0;
}