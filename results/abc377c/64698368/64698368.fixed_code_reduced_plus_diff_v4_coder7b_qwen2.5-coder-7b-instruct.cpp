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

struct phash{
    inline size_t operator()(const pair<int,int> & p) const{
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int N,M; 
set<pair<int,int>,phash> st;

void set_insert(int a,int b){
    if(0<=a && a<N && 0<=b && b<N) st.insert({a,b});
}

bool can_capture(int x,int y){
    vector<pair<int,int>> vc={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    for(auto [dx,dy]:vc){
        int nx=x+dx,ny=y+dy;
        if(0<=nx&&nx<N&&0<=ny&&ny<N&&st.count({nx,ny})) return true;
    }
    return false;
}

int main() {
    cin>>N>>M;

    rep(i,M){
        int a,b; cin>>a>>b;
        a--; b--;
        if(!can_capture(a,b)) set_insert(a,b);
    }

    ll N_=pow(N,2);
    cout<<N_-st.size();
}