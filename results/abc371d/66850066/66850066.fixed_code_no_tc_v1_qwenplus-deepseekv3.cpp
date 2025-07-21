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
    vector<ll> P(N+1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> x_index;
    rep(i, N){
        x_index.emplace_back(X[i], i);
    }
    sort(all(x_index));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto lower = lower_bound(all(x_index), make_pair(L, 0));
        auto upper = upper_bound(all(x_index), make_pair(R, N));
        
        int l = lower - x_index.begin();
        int r = upper - x_index.begin();
        
        int first_index = (l < N) ? x_index[l].second : N;
        int last_index = (r > 0) ? x_index[r-1].second : -1;
        
        if (last_index < first_index || last_index == -1 || first_index == N) {
            cout << 0 << endl;
        } else {
            cout << P[last_index+1] - P[first_index] << endl;
        }
    }
}