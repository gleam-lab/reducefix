#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> existing;
    set<pair<long long, long long>> attacked;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing.insert({a, b});

        // Mark all 8 possible attack positions
        vector<pair<long long, long long>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto &move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // The number of safe positions is total positions minus existing and attacked positions
    // But existing positions are already included in attacked positions if they are attacked by others.
    // So the safe positions are:
    // Total positions - (existing positions + attacked positions - existing positions that are also attacked)
    // Which simplifies to total positions - (existing positions union attacked positions)
    
    // To compute (existing union attacked), we merge both sets
    set<pair<long long, long long>> union_set;
    union_set.insert(existing.begin(), existing.end());
    union_set.insert(attacked.begin(), attacked.end());

    long long total_safe = N * N - union_set.size();

    cout << total_safe << endl;

    return 0;
}