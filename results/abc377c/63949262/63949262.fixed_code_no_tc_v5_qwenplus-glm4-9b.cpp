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

    set<pair<int, int>> occupied;
    for (long long i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    long long count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool can_place = true;
            for (int x = -2; x <= 2; ++x) {
                for (int y = -2; y <= 2; ++y) {
                    if (abs(x) + abs(y) == 2) {
                        int dx = x + i, dy = y + j;
                        if (dx >= 1 && dx <= N && dy >= 1 && dy <= N && occupied.count({dx, dy})) {
                            can_place = false;
                            break;
                        }
                    }
                }
                if (!can_place) break;
            }
            if (can_place) {
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}