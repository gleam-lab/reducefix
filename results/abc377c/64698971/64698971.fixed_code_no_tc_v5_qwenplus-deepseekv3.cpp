#include <bits/stdc++.h>
using namespace std;

int N, M;
set<pair<int, int>> dangerous;
set<pair<int, int>> existing;

void mark_dangerous(int a, int b) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 0 && x < N && y >= 0 && y < N) {
            dangerous.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        existing.insert({a, b});
        mark_dangerous(a, b);
    }

    long long total_safe = (long long)N * N - dangerous.size() - existing.size();
    cout << total_safe << endl;
    return 0;
}