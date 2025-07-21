#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> attacked;
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        for (auto [dx, dy] : moves) {
            int nx = a + dx;
            int ny = b + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                attacked.insert({nx, ny});
            }
        }
    }

    ll total_squares = (ll)N * N;
    ll safe_squares = total_squares - attacked.size() - M; // Subtract M because the pieces themselves are occupied
    cout << safe_squares << endl;
    return 0;
}