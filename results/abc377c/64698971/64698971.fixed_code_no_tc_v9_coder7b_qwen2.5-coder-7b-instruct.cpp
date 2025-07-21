#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n - 1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(), (a).end()
#define ALL_(a) (a), (a) + size(a)
#define IF_T if (Is_test)

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N, vector<bool>(N, false));
    vector<pair<ll, ll>> pieces(M);
    vector<vector<bool>> captured(N, vector<bool>(N, false));

    rep(i, M) {
        cin >> pieces[i].first >> pieces[i].second;
        pieces[i].first--;
        pieces[i].second--;
        grid[pieces[i].first][pieces[i].second] = true;
    }

    vector<pair<ll, ll>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    rep(k, M) {
        ll x = pieces[k].first, y = pieces[k].second;
        rep(dir, 8) {
            ll dx = directions[dir].first, dy = directions[dir].second;
            ll nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                captured[nx][ny] = true;
            }
        }
    }

    ll result = 0;
    rep(i, N) {
        rep(j, N) {
            if (!grid[i][j] && !captured[i][j]) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}