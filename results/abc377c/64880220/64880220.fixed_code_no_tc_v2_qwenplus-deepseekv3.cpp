#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<long long, long long>> attacked;
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

    for (auto [a, b] : pieces) {
        attacked.insert({a, b});
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    cout << N * N - attacked.size() << endl;
    return 0;
}