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
    vector<ll> P(N+1);
    vector<pair<int, int>> sorted_X(N); // stores X[i] and original index
    
    rep(i, N) {
        int x;
        cin >> x;
        sorted_X[i] = {x, i};
    }
    
    // Sort based on X values
    sort(all(sorted_X));
    
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<int> original_to_sorted(N);
    rep(i, N) {
        original_to_sorted[sorted_X[i].second] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find first X >= L
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0));
        int l = it_l - sorted_X.begin();
        
        // Find first X > R
        auto it_r = upper_bound(all(sorted_X), make_pair(R, N));
        int r = it_r - sorted_X.begin();
        
        // Now we need to get the original indices and calculate sum
        ll sum = 0;
        for (int i = l; i < r; ++i) {
            int original_idx = sorted_X[i].second;
            sum += (P[original_idx+1] - P[original_idx]);
        }
        
        cout << sum << endl;
    }
}