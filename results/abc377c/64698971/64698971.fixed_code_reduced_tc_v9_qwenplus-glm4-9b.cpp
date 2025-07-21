#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
const int dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};

bool in_bounds(int x, int y, int n) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void capture_area(int x, int y, int n, set<pair<int, int>>& captured) {
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (in_bounds(nx, ny, n)) {
            captured.insert({nx, ny});
            capture_area(nx, ny, n, captured);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> captured;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        capture_area(a, b, n, captured);
    }

    long long total_empty = n * n - captured.size();
    cout << total_empty << endl;

    return 0;
}