#include <bits/stdc++.h>

using namespace std;
using ll = long long;
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
    rep(i, N) cin >> X[i];
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create a sorted vector of pairs (X[i], i) instead of map to better handle duplicates and ensure ordering
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
        
        // Use lower_bound and upper_bound on the sorted vector
        int l = distance(x_index.begin(), lower_bound(all(x_index), make_pair(L, -1)));
        int r = distance(x_index.begin(), upper_bound(all(x_index), make_pair(R, N)));

        // Output the sum of weights in the range [l, r)
        cout << P[r] - P[l] << endl;
    }
}