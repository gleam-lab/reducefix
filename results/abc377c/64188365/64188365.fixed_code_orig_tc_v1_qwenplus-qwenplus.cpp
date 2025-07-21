#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll N;
    int M;
    cin >> N >> M;

    set<pair<int, int>> occupied;
    vector<pair<int, int>> pieces(M);

    // Read all pieces
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces[i] = {a, b};
        occupied.insert({a, b});
    }

    // Define the 8 knight-style move patterns
    const vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Mark threatened positions
    for (auto [x, y] : pieces) {
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                occupied.insert({nx, ny});
            }
        }
    }

    // Total cells minus number of unsafe (occupied or threatened) cells
    cout << N * N - (ll)occupied.size() << endl;
}