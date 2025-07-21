#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied_or_attacked;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied_or_attacked.insert({a, b});

        // Calculate all 8 possible attack positions
        vector<pair<long long, long long>> directions = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto& pos : directions) {
            if (pos.first >= 1 && pos.first <= N && pos.second >= 1 && pos.second <= N) {
                occupied_or_attacked.insert(pos);
            }
        }
    }

    long long total = N * N;
    long long unsafe = occupied_or_attacked.size();
    long long safe = total - unsafe;

    cout << safe << '\n';

    return 0;
}