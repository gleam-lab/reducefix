#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    set<pair<int, int>> threatened;

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        for (int k = 0; k < 8; ++k) {
            int nx = a + dx[k];
            int ny = b + dy[k];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                threatened.insert({nx, ny});
            }
        }
    }

    for (const auto& pos : occupied) {
        threatened.erase(pos);
    }

    int64_t total_safe = (int64_t)N * N - occupied.size() - threatened.size();
    cout << total_safe << '\n';

    return 0;
}