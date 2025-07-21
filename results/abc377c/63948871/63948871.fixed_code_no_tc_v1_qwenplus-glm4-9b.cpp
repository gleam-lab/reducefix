#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;

    for (long long i = 0; i < M; i++) {
        long long x, y;
        cin >> x >> y;
        occupied.insert({x, y});
    }

    long long ans = (N * N);

    // Check all possible positions for placement
    FOR_U(i, 1, N + 1, 1) {
        FOR_U(j, 1, N + 1, 1) {
            bool canPlace = true;
            // Check if the position can be captured by any existing piece
            FOR_U(d, -2, 2 + 1, 1) {
                FOR_U(e, -2, 2 + 1, 1) {
                    long long nx = i + d, ny = j + e;
                    if (nx > 0 && nx <= N && ny > 0 && ny <= N && occupied.count({nx, ny}) > 0) {
                        canPlace = false;
                        break;
                    }
                }
                if (!canPlace) break;
            }
            if (canPlace) {
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}