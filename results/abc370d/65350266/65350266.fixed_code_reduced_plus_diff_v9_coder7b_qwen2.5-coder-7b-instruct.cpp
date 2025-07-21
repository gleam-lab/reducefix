#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = LLONG_MAX / 2;

struct UnionFind {
    vector<ll> par;
    UnionFind(ll n): par(n,-1){}
    bool unite(ll x, ll y){
        x=find(x); y=find(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x] += par[y];
        par[y]=x;
        return true;
    }
    ll find(ll x){
        if(par[x]<0)return x;
        else return par[x]=find(par[x]);
    }
    ll size(ll x){
        return -par[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    UnionFind uf_h(h*w+1), uf_w(h*w+1);
    set<P> st;
    rep(i,h)rep(j,w)st.insert(P(i,j));

    while(q--){
        int r, c;
        cin >> r >> c;
        --r; --c;
        int id = r * w + c + 1;
        if(!uf_h.find(id)){
            auto it = st.lower_bound(P(r,c));
            if(it != st.end()){
                int ni = (*it).first, nj = (*it).second;
                if(ni == r && nj > c){
                    uf_h.unite(id, ni * w + nj + 1);
                }
                else if(nj == c && ni > r){
                    uf_w.unite(id, ni * w + nj + 1);
                }
            }
            if(it != st.begin()){
                it--;
                int ni = (*it).first, nj = (*it).second;
                if(ni == r && nj < c){
                    uf_h.unite(id, ni * w + nj + 1);
                }
                else if(nj == c && ni < r){
                    uf_w.unite(id, ni * w + nj + 1);
                }
            }
        }
        st.erase(st.find(P(r,c)));
    }

    unordered_set<ll> root_h, root_w;
    for(auto p: st){
        root_h.insert(uf_h.find(p.first * w + p.second + 1));
        root_w.insert(uf_w.find(p.first * w + p.second + 1));
    }
    cout << root_h.size() + root_w.size() << '\n';
    return 0;
}