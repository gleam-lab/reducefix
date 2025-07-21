#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe;
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        for (auto move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafeCount = unsafe.size();
    long long safe = total - unsafeCount - M;

    cout << safe << endl;
    return 0;
}