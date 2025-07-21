#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> forbidden;
    set<pair<long long, long long>> existing;

    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing.insert({a, b});
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N && existing.find({x, y}) == existing.end()) {
                forbidden.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long forbidden_count = forbidden.size();
    long long existing_count = existing.size();
    long long safe = total - existing_count - forbidden_count;

    cout << safe << endl;

    return 0;
}