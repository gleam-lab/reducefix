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

int N, M;
vector<vector<bool>> board;

bool isValid(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    cin >> N >> M;
    board.resize(N, vector<bool>(N, false));

    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    rep(i, M) {
        int a, b; cin >> a >> b;
        a--, b--;
        board[a][b] = true;
    }

    ll validPositions = 0;

    rep(i, N) {
        rep(j, N) {
            bool isAttacked = false;
            for (auto& dir : directions) {
                int nx = i + dir.first;
                int ny = j + dir.second;
                if (isValid(nx, ny) && board[nx][ny]) {
                    isAttacked = true;
                    break;
                }
            }
            if (!isAttacked) validPositions++;
        }
    }

    cout << validPositions << endl;

    return 0;
}