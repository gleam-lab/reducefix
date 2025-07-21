#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> occupied;
    vector<pair<long long, long long>> pieces(m);

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
    }

    long long safe_squares = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            bool is_safe = true;
            const vector<pair<long long, long long>> moves = {
                {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
            };

            for (const auto& move : moves) {
                long long x = i + move.first, y = j + move.second;
                if (x < 1 || x > n || y < 1 || y > n || occupied.count({x, y})) {
                    is_safe = false;
                    break;
                }
            }

            if (is_safe) {
                safe_squares++;
            }
        }
    }

    cout << safe_squares << endl;
    return 0;
}