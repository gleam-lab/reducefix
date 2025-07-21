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
    vector<int> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> x_with_index;
    rep(i, N) {
        x_with_index.emplace_back(X[i], i);
    }
    sort(all(x_with_index));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto it_l = lower_bound(all(x_with_index), make_pair(L, 0));
        auto it_r = upper_bound(all(x_with_index), make_pair(R, N));
        
        int l = (it_l == x_with_index.end()) ? N : it_l->second;
        int r = (it_r == x_with_index.end()) ? N : it_r->second;
        
        if (l >= r) {
            cout << 0 << endl;
        } else {
            cout << P[r] - P[l] << endl;
        }
    }
}