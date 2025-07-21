#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> attacked;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // Check all 8 possible attack positions
        const long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // Total squares is N*N
    // Invalid squares are those already occupied or under attack
    // But occupied squares are already part of attacked squares if they are under attack
    // So total invalid squares is the union of occupied and attacked
    set<pair<long long, long long>> invalid;
    invalid.insert(occupied.begin(), occupied.end());
    invalid.insert(attacked.begin(), attacked.end());

    long long ans = N * N - invalid.size();
    cout << ans << '\n';

    return 0;
}