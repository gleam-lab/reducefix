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
    auto erase  = [&](int r, int c){
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
        auto it = Y[C].upper_bound(R);
        //up
        if(it != Y[C].begin()){
            it--;
            erase(*it, C);
        }

        it = Y[C].upper_bound(R);
        if(it != Y[C].end()){
            erase(*it, C);
        }

        it = X[R].upper_bound(C);
        if(it != X[R].begin()){
            it--;
            erase(R,*it);
        }

        it = X[R].upper_bound(C);
        if(it != X[R].end()){
            erase(R,*it);
        }
    }
    cout << ans - cnt << endl;
    return 0;
}