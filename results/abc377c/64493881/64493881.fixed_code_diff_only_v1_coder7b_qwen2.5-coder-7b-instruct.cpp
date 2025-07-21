#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vector<ll>>
#define vvb vector<vector<bool>>
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()

class Solution {
public:
    ll solve(ll n, ll m, vvi &pos) {
        vb board(n*n, true);
        rep(i, 0, m) {
            ll x = pos[i][0] - 1, y = pos[i][1] - 1;
            ll dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
            rep(j, 0, 8) {
                ll nx = x + dx[j], ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    board[nx * n + ny] = false;
                }
            }
        }
        ll res = 0;
        rep(i, 0, n*n) {
            if (board[i]) res++;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Solution sol;
    ll n, m; cin >> n >> m;
    vvi pos(m, vi(2));
    rep(i, 0, m) {
        cin >> pos[i][0] >> pos[i][1];
    }
    cout << sol.solve(n, m, pos) << endl;
    return 0;
}