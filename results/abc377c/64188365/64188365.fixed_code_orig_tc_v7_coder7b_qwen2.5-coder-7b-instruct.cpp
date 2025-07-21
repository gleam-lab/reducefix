#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return x != other.x ? x < other.x : y < other.y;
    }
};

bool isValidMove(const vector<Point>& pieces, int n, int x, int y) {
    for (const auto& p : pieces) {
        int dx = abs(p.x - x);
        int dy = abs(p.y - y);
        
        // Check if the move is within the capturing range
        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    set<Point> pieces;
    for (long long i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        pieces.insert({a, b});
    }
    
    long long result = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!pieces.count({i, j}) && isValidMove(pieces, n, i, j)) {
                ++result;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}