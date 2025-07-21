#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define ALL_(a) (a),(a)+size(a)
#define IF_T if(Is_test)

#define ll long long
using namespace std;

const vector<pair<int, int>> knight_moves = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isValid(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> reachable_cells;

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        rep(j, knight_moves.size()) {
            int dx = knight_moves[j].first;
            int dy = knight_moves[j].second;

            rep(k, 2) {
                int new_x = a + dx * (k + 1);
                int new_y = b + dy * (k + 1);

                if (isValid(new_x, new_y, N)) {
                    reachable_cells.insert({new_x, new_y});
                }
            }
        }
    }

    ll total_cells = N * N;
    ll available_cells = total_cells - reachable_cells.size();

    cout << available_cells << endl;

    return 0;
}