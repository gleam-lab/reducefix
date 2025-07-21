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

int N,M; 
set<pair<int,int>> st;

void set_insert(int a,int b){
    if(0<=a && a<N && 0<=b && b<N) st.insert({a,b});
}

int main() {
    cin>>N>>M;

    vector<pair<int,int>> vc={{0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    rep(i,M){
        int a,b; cin>>a>>b;
        a--; b--;
        for(auto x:vc) set_insert(a+x.first,b+x.second);
    }

    // for(auto x:st) cout<<x.first<<' '<<x.second<<endl;
    ll N_=pow(N,2);
    cout<<(N_-st.size())<<endl;
}