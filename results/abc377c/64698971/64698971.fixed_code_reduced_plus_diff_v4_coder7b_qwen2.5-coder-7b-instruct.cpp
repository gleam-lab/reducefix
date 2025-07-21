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
unordered_set<pair<int,int>, phash> st;

vector<pair<int,int>> vc = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    cin >> N >> M;
    
    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--; // Convert 1-based to 0-based indexing
        for(auto& dir : vc) {
            int nx = a + dir.first, ny = b + dir.second;
            if(isValid(nx, ny)) st.insert({nx, ny});
        }
    }

    ll N_ = pow(N, 2);
    cout << N_ - (ll)st.size();
}