#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> captured;
    vector<long long> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<long long> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        captured.insert({a, b});
        
        for (long long j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                captured.insert({x, y});
            }
        }
    }
    cout << N * N - captured.size() << endl;
    return 0;
}