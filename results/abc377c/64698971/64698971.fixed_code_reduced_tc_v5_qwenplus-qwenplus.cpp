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

struct phash {
    inline size_t operator()(const pair<int,int> & p) const {
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 16);
    }
};

int N,M;
unordered_set<pair<int,int>, phash> st;

void set_insert(int a, int b) {
    // No need to check bounds because we're using unordered_set
    st.insert({a, b});
}

int main() {
    cin>>N>>M;

    vector<pair<int,int>> vc={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    rep(i,M){
        int a,b; cin>>a>>b;
        // Convert to 0-based index
        a--; b--;
        // Check all 8 possible attack positions
        for(auto x:vc) set_insert(a+x.first, b+x.second);
        // Also insert the position itself since it's already occupied
        st.insert({a, b});
    }

    // Total number of cells is N*N
    ll total_cells = (ll)N * (ll)N;
    // Number of forbidden cells = size of the set
    cout << total_cells - (ll)st.size();
}