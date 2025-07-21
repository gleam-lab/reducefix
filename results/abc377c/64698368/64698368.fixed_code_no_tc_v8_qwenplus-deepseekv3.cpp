#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> threatened;
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    unordered_set<long long> existing;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        existing.insert(a * N + b);
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                threatened.insert(x * N + y);
            }
        }
    }

    long long total_squares = N * N;
    long long safe_squares = total_squares - threatened.size() - existing.size();
    cout << safe_squares << endl;
    
    return 0;
}