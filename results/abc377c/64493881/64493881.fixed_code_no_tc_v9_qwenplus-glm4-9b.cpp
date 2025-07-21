#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int solve() {
        long long N, M;
        cin >> N >> M;

        set<pair<int, int>> occupied;

        for (long long i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            occupied.insert({a, b});
        }

        long long possiblePositions = N * N;
        long long forbiddenPositions = 0;

        for (const auto& p : occupied) {
            int x = p.first;
            int y = p.second;

            // Check the 3x3 area around the piece
            for (int i = max(1, x - 2); i <= min(N, x + 2); ++i) {
                for (int j = max(1, y - 2); j <= min(N, y + 2); ++j) {
                    forbiddenPositions++;
                }
            }
        }

        possiblePositions -= forbiddenPositions;

        cout << possiblePositions << endl;

        return 0;
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}