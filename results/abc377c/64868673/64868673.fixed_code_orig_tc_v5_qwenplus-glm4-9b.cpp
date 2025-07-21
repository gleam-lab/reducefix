#include <bits/stdc++.h>
using namespace std;
long long answer = 0;
int n, m;
vector<pair<int, int>> pieces;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pieces.emplace_back(x, y);
    }

    vector<bool> can_be_captured(n * n + 1, false);
    for (auto& piece : pieces) {
        int x = piece.first;
        int y = piece.second;
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (i == 0 && j == 0) continue;
                int nx = x + i;
                int ny = y + j;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                    can_be_captured[(nx - 1) * n + ny - 1] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = (i * n + j);
            if (!can_be_captured[index]) {
                answer++;
            }
        }
    }

    cout << answer << endl;
    return 0;
}