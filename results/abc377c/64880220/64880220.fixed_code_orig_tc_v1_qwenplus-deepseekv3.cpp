#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> marked;
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        marked.insert({a, b});
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                marked.insert({x, y});
            }
        }
    }

    cout << N * N - marked.size() << endl;
    return 0;
}