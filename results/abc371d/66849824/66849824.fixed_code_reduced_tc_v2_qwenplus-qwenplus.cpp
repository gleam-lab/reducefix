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
    
    // Create a sorted vector of pairs (X[i], i) instead of map
    vector<pair<ll, int>> x_indices(N);
    rep(i, N) {
        x_indices[i] = {X[i], i};
    }
    sort(all(x_indices));

    // Precompute prefix sums for the sorted indices
    vector<ll> prefix_sum(N+1);
    rep(i, N) {
        prefix_sum[i+1] = prefix_sum[i] + P[x_indices[i].second + 1] - P[x_indices[i].second];
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;
        
        // Binary search to find range in sorted X values
        int left = 0, right = N;
        while (right > left) {
            int mid = (left + right) / 2;
            if (x_indices[mid].first < L) left = mid + 1;
            else right = mid;
        }
        l = left;
        
        left = 0, right = N;
        while (right > left) {
            int mid = (left + right) / 2;
            if (x_indices[mid].first <= R) left = mid + 1;
            else right = mid;
        }
        r = right;
        
        cout << prefix_sum[r] - prefix_sum[l] << endl;
    }
}