#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> threatened;
    vector<pair<int, int>> directions = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // converting to 0-based index for easier calculations

        for (const auto& dir : directions) {
            int x = a + dir.first;
            int y = b + dir.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                threatened.insert({x, y});
            }
        }
    }

    ll total_squares = (ll)N * N;
    ll safe_squares = total_squares - threatened.size() - M;
    cout << safe_squares << endl;

    return 0;
}