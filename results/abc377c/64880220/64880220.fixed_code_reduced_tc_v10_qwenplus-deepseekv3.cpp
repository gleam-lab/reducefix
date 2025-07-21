#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> threatened;

    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (int j = 0; j < 8; j++) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert({x, y});
            }
        }
    }

    // The total unavailable squares are those that are either occupied or threatened
    set<pair<long long, long long>> unavailable;
    unavailable.insert(occupied.begin(), occupied.end());
    unavailable.insert(threatened.begin(), threatened.end());

    long long ans = N * N - unavailable.size();
    cout << ans << endl;

    return 0;
}