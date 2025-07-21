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

    // Create a vector of pairs (X[i], i) and sort it
    vector<pair<int, int>> sorted_X;
    rep(i, N) sorted_X.emplace_back(X[i], i);
    sort(all(sorted_X));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find the first X[i] >= L using binary search
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0));
        // Find the first X[i] > R using binary search
        auto it_r = upper_bound(all(sorted_X), make_pair(R, N));
        
        // Calculate the sum for the range
        ll ans = 0;
        if (it_l != sorted_X.end() && it_r != sorted_X.begin()) {
            int l_idx = it_l - sorted_X.begin();
            int r_idx = it_r - sorted_X.begin();
            
            // The actual indices in the original array are sorted_X[i].second
            // But since prefix sums are contiguous, we need to find the min and max indices
            int min_idx = N, max_idx = -1;
            for (int i = l_idx; i < r_idx; ++i) {
                int original_idx = sorted_X[i].second;
                min_idx = min(min_idx, original_idx);
                max_idx = max(max_idx, original_idx);
            }
            
            if (min_idx <= max_idx) {
                ans = P[max_idx + 1] - P[min_idx];
            }
        }
        
        cout << ans << endl;
    }
}