#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)

#define ll long long
using namespace std;

int N, M;
set<pair<int, int>> occupied;

void mark_threatened(int a, int b) {
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (auto [dx, dy] : moves) {
        int nx = a + dx;
        int ny = b + dy;
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
            occupied.insert({nx, ny});
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // Mark all positions threatened by this piece
        mark_threatened(a, b);
    }

    // Total squares minus the threatened or occupied ones
    ll total = (ll)N * N;
    cout << total - (ll)occupied.size() << endl;
}