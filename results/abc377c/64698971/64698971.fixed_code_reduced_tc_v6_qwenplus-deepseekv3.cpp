#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> threatened;
    vector<pair<int, int>> existing;

    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        existing.emplace_back(a, b);
        for (const auto &move : moves) {
            int ni = a + move.first;
            int nj = b + move.second;
            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                threatened.emplace(ni, nj);
            }
        }
    }

    // Existing pieces are also considered as occupied
    for (const auto &pos : existing) {
        threatened.insert(pos);
    }

    ll total_squares = (ll)N * N;
    ll safe_squares = total_squares - threatened.size();
    cout << safe_squares << endl;

    return 0;
}