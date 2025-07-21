#include <iostream>
#include <set>

using namespace std;

#define N 1000000000

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> invalid_positions;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        // Check all the positions that this piece can capture
        invalid_positions.insert({a + 2, b + 1});
        invalid_positions.insert({a + 1, b + 2});
        invalid_positions.insert({a - 1, b + 2});
        invalid_positions.insert({a - 2, b + 1});
        invalid_positions.insert({a - 2, b - 1});
        invalid_positions.insert({a - 1, b - 2});
        invalid_positions.insert({a + 1, b - 2});
        invalid_positions.insert({a + 2, b - 1});
    }

    // Total squares minus the number of invalid squares
    cout << (n * n) - invalid_positions.size();

    return 0;
}