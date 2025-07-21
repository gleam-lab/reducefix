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
    vector<int> X(N), P(N+1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> sorted_X(N);
    rep(i, N){
        sorted_X[i] = {X[i], i};
    }
    sort(all(sorted_X));
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        auto comp = [](const pair<int, int>& a, int b) { return a.first < b; };
        int l = lower_bound(all(sorted_X), L, comp) - sorted_X.begin();
        int r = upper_bound(all(sorted_X), R, comp) - sorted_X.begin();
        
        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}