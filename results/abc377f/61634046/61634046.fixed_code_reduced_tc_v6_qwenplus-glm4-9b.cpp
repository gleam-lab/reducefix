#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Position {
    int x, y;
};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<Position> positions(m);
    for (int i = 0; i < m; ++i) {
        cin >> positions[i].x >> positions[i].y;
    }

    long long total_empty = n * n;
    long long captured = 0;

    // Check capture by row and column
    for (int i = 1; i <= n; ++i) {
        captured += count_if(positions.begin(), positions.end(), [i](const Position &p) { return p.x == i; });
        captured += count_if(positions.begin(), positions.end(), [i](const Position &p) { return p.y == i; });
    }

    // Check capture by diagonals
    for (int i = 1; i <= n; ++i) {
        captured += count_if(positions.begin(), positions.end(), [i](const Position &p) { return p.x + p.y == i; });
        captured += count_if(positions.begin(), positions.end(), [i](const Position &p) { return p.x - p.y == i; });
    }

    // Calculate the number of empty places where you can place your piece
    total_empty -= captured;

    cout << total_empty << endl;

    return 0;
}