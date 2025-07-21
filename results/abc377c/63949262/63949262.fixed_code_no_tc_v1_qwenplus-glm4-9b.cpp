#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define INF 1000000000

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> reachable;
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        // Add attacking positions
        reachable.insert({a + 2, b + 1});
        reachable.insert({a + 1, b + 2});
        reachable.insert({a - 1, b + 2});
        reachable.insert({a - 2, b + 1});
        reachable.insert({a - 2, b - 1});
        reachable.insert({a - 1, b - 2});
        reachable.insert({a + 1, b - 2});
        reachable.insert({a + 2, b - 1});
    }

    long long count = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            // Check if the current position can be attacked by any piece
            bool can_attack = false;
            for (const auto& p : reachable) {
                if (p.first == i && p.second == j) {
                    can_attack = true;
                    break;
                }
            }
            if (!can_attack) {
                // If not attacked, it's a valid position for placing a piece
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}