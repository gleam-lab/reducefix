#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> marked;
    vector<pair<long long, long long>> pieces(M);
    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        marked.insert({a, b});
    }

    for (auto p : pieces) {
        long long a = p.first;
        long long b = p.second;
        for (int i = 0; i < 8; ++i) {
            long long x = a + dx[i];
            long long y = b + dy[i];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                marked.insert({x, y});
            }
        }
    }

    cout << N * N - marked.size() << endl;
    return 0;
}