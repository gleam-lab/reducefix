#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n) ; ++i)
#define rep1(i,n) for(int i = 1; i < (int)(n) ; ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (int)n-1; i >= 1 ; --i)

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvvbool>;

using vs = vector<string>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vvb coo(h+2, vb(w+2, true));
    set<int> R, C;
    rep(i,w+2) R.insert(i);
    rep(i,h+2) C.insert(i);
    vector<set<int>> row(h+2, R);
    vector<set<int>> col(w+2, C);

    auto erase = [&](int i, int j){
        if(i*j == 0) return;
        row[i].erase(j);
        col[j].erase(i);
        coo[i][j] = false;
    };

    auto bin = [&](){
        {
            auto &st = row[r];
            auto it = st.upper_bound(c);
            if(it != st.begin()){
                --it;
                erase(r, *it);
            }

            it = st.lower_bound(c);
            if(it != st.end() && *(++it) != c){
                erase(r, *it);
            }
        }

        {
            auto &st = col[c];
            auto it = st.upper_bound(r);
            if(it != st.begin()){
                --it;
                erase(*it, c);
            }

            it = st.lower_bound(r);
            if(it != st.end() && *(++it) != r){
                erase(*it, c);
            }
        }
    };

    while(q--){
        cin >> r >> c;
        if(coo[r][c]){
            erase(r,c);
            continue;
        }
        bin();
    }

    int ans = 0;
    rep(i,h) rep(j,w) ans += coo[i+1][j+1];

    cout << ans << '\n';
    return 0;
}