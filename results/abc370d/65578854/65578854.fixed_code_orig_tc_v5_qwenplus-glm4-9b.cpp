#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> X(H), Y(W);
    rep(i, H) rep(j, W){
        X[i].insert(j);
        Y[j].insert(i);
    }
    ll ans = H * W;
    ll cnt = 0;
    auto erase = [&](int r, int c){
        cnt++;
        X[r].erase(c);
        Y[c].erase(r);
    };
    rep(itr, Q){
        int R, C;
        cin >> R >> C;
        R--; C--;
        if(X[R].count(C)){
            erase(R, C);
            continue;
        }
        // Bombing process
        bool left = (C > 0 && X[R].count(C - 1));
        bool right = (C < W - 1 && X[R].count(C + 1));
        bool up = (R > 0 && Y[C].count(R - 1));
        bool down = (R < H - 1 && Y[C].count(R + 1));
        
        if(left) erase(R, C - 1);
        if(right) erase(R, C + 1);
        if(up) erase(R - 1, C);
        if(down) erase(R + 1, C);
        
        // If there are walls on both sides, remove the wall in between if any
        if(left && right) erase(R, C);
        if(up && down) erase(R, C);
    }
    cout << ans - cnt << endl;
    return 0;
}