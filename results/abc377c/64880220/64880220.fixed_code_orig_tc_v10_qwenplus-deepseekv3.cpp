#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> threatened;

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        for (int k = 0; k < 8; ++k) {
            long long x = a + dx[k];
            long long y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert({x, y});
            }
        }
    }

    set<pair<long long, long long>> unsafe;
    unsafe.insert(occupied.begin(), occupied.end());
    unsafe.insert(threatened.begin(), threatened.end());

    long long safe = N * N - unsafe.size();
    cout << safe << endl;

    return 0;
}