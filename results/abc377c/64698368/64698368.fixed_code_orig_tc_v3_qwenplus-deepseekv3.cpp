#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based or 1-based? Original code uses 0-based.
        for (const auto& dir : directions) {
            long long ni = a + dir.first;
            long long nj = b + dir.second;
            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                attacked.insert({ni, nj});
            }
        }
    }

    long long total = N * N;
    long long unsafe = attacked.size();
    long long safe = total - unsafe - M; // Subtract M because the original M pieces are already placed and not counted in attacked.
    cout << safe << endl;

    return 0;
}