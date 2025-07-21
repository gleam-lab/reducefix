#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define i128 long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 N;
    int M;
    cin >> N >> M;

    set<pair<i128, i128>> pieces;
    set<pair<i128, i128>> threatened;

    for (int i = 0; i < M; ++i) {
        i128 a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // All 8 possible knight moves
        i128 dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        i128 dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int j = 0; j < 8; ++j) {
            i128 nx = a + dx[j];
            i128 ny = b + dy[j];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                threatened.insert({nx, ny});
            }
        }
    }

    // Calculate safe squares
    i128 total_squares = N * N;
    i128 occupied = pieces.size();
    i128 threat_count = threatened.size();

    // Remove the squares that are both occupied and threatened (they were counted twice)
    i128 overlap = 0;
    for (const auto& p : pieces) {
        if (threatened.count(p)) {
            overlap++;
        }
    }

    i128 safe_squares = total_squares - occupied - (threat_count - overlap);
    cout << safe_squares << endl;

    return 0;
}