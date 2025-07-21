#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    set<pair<int, int>> walls;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            walls.insert({i, j});
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        auto pos = make_pair(R, C);
        if (walls.find(pos) != walls.end()) {
            walls.erase(pos);
        } else {
            // Search up
            auto it = walls.lower_bound({R, C});
            if (it != walls.begin()) {
                --it;
                if (it->second == C && it->first < R) {
                    walls.erase(it);
                    continue;
                }
                ++it;
            }

            // Search down
            it = walls.lower_bound({R + 1, C});
            if (it != walls.end() && it->second == C) {
                walls.erase(it);
                continue;
            }

            // Search left
            it = walls.lower_bound({R, 0});
            pair<int, int> left_candidate = {0, 0};
            bool found_left = false;
            for (; it != walls.end() && it->first == R; ++it) {
                if (it->second < C) {
                    left_candidate = *it;
                    found_left = true;
                } else {
                    break;
                }
            }
            if (found_left) {
                walls.erase(left_candidate);
                continue;
            }

            // Search right
            it = walls.lower_bound({R, C + 1});
            if (it != walls.end() && it->first == R) {
                walls.erase(it);
                continue;
            }
        }
    }

    cout << walls.size() << '\n';

    return 0;
}