#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> threatened;
    vector<pair<long long, long long>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;

        for (auto dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                threatened.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long safe = total - threatened.size() - M; // Subtract M for the existing pieces' positions
    cout << safe << endl;

    return 0;
}