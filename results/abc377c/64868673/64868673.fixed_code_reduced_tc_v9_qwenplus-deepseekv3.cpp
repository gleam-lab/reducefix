#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);
        unsafe.insert({a, b});
    }

    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for (const auto& piece : pieces) {
        long long a = piece.first;
        long long b = piece.second;
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe_count = unsafe.size();
    long long safe = total - unsafe_count;
    cout << safe << endl;

    return 0;
}