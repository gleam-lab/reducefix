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
    vector<pair<int, int>> sortedX(N); // Store both X[i] and its original index
    vector<int> P(N+1, 0);
    
    rep(i, N) {
        cin >> sortedX[i].first;
        sortedX[i].second = i;
    }
    
    // Sort the X values while keeping track of original indices
    sort(all(sortedX));
    
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find first element >= L
        auto it_l = lower_bound(all(sortedX), make_pair(L, 0));
        // Find first element > R
        auto it_r = upper_bound(all(sortedX), make_pair(R, N));
        
        int l_idx = (it_l == sortedX.end()) ? N : it_l->second;
        int r_idx = (it_r == sortedX.end()) ? N : it_r->second;
        
        // Swap if necessary (since original indices might not be in order)
        if (l_idx > r_idx) swap(l_idx, r_idx);
        
        // The sum should be from min(l_idx, r_idx) to max(l_idx, r_idx)
        // But we need to include all elements between L and R inclusive
        // So we need to find the range in original indices where X[i] is between L and R
        
        // Alternative approach: sum P[r_idx] - P[l_idx] is incorrect
        // Because the original indices might not be contiguous
        
        // Correct approach: sum all P[i+1] - P[i] where X[i] is between L and R
        // Which is same as sum of all p[i] where X[i] is between L and R
        
        int sum = 0;
        for (auto it = it_l; it != it_r; ++it) {
            int original_idx = it->second;
            sum += P[original_idx + 1] - P[original_idx];
        }
        
        cout << sum << endl;
    }
}