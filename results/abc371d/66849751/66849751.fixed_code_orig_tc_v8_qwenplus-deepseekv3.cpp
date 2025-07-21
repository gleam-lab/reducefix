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
    vector<int> X(N);
    vector<ll> P(N+1, 0);
    rep(i, N) cin >> X[i];
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    vector<pair<int, int>> x_with_index;
    rep(i, N){
        x_with_index.emplace_back(X[i], i);
    }
    sort(all(x_with_index));

    vector<int> sorted_X(N);
    rep(i, N) sorted_X[i] = x_with_index[i].first;

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto it_l = lower_bound(all(sorted_X), L);
        auto it_r = upper_bound(all(sorted_X), R);
        int l = it_l - sorted_X.begin();
        int r = it_r - sorted_X.begin();
        ll ans = P[x_with_index[r-1].second + 1] - P[x_with_index[l].second];
        cout << ans << endl;
    }
}