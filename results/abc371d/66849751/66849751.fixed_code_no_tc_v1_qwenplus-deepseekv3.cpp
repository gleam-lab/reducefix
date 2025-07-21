#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int N;
    cin >> N;
    vector<int> X(N), p(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> p[i];
    
    vector<int> P(N+1, 0);
    rep(i, N) P[i+1] = P[i] + p[i];
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        auto it_l = lower_bound(all(X), L);
        auto it_r = upper_bound(all(X), R);
        
        int l = distance(X.begin(), it_l);
        int r = distance(X.begin(), it_r);
        
        cout << P[r] - P[l] << endl;
    }
}