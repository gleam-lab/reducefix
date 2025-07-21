#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long n, m;
vector<pair<int, int>> pieces;

// Function to check if a square can be occupied
bool canOccupy(int a, int b) {
    for (auto& p : pieces) {
        if (p.first == a || p.second == b ||
            (abs(p.first - a) + abs(p.second - b)) == abs(p.first - a) - abs(p.second - b) ||
            (abs(p.first - a) + abs(p.second - b)) == abs(p.second - b) + abs(p.first - a)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pieces.resize(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
    }

    // Count the number of squares that can be occupied
    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (canOccupy(i, j)) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}