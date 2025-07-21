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
vector<pair<int, int>> pieces;

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    cin >> N >> M;

    vector<vector<bool>> board(N, vector<bool>(N, false));
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pieces.push_back({a, b});
        board[a][b] = true;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool canPlace = true;
            rep(k, M) {
                int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
                int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
                rep(l, 8) {
                    int nx = i + dx[l];
                    int ny = j + dy[l];
                    if (isValid(nx, ny) && board[nx][ny]) {
                        canPlace = false;
                        break;
                    }
                }
                if (!canPlace) break;
            }
            if (canPlace) count++;
        }
    }

    cout << count << endl;

    return 0;
}