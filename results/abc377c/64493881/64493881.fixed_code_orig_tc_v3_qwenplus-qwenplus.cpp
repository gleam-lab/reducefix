#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store occupied and threatened positions
    set<pair<long long, long long>> blocked;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        blocked.insert({a, b});
        for (auto [dx, dy] : moves) {
            long long na = a + dx;
            long long nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                blocked.insert({na, nb});
            }
        }
    }

    // Total number of cells: N*N
    // Subtract the number of blocked cells
    cout << (N * N - blocked.size()) << endl;

    return 0;
}