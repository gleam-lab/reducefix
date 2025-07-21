#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> forbidden;
    set<pair<int, int>> existing;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        existing.emplace(a, b);

        // All possible knight moves
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.emplace(x, y);
            }
        }
    }

    // The existing pieces are also forbidden, but they might not be in 'forbidden'
    // So we need to add them to the forbidden set if they are not already there
    for (const auto& p : existing) {
        forbidden.insert(p);
    }

    long long total = N * N;
    long long forbidden_count = forbidden.size();
    cout << total - forbidden_count << '\n';

    return 0;
}