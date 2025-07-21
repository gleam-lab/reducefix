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
    vector<int> P(N+1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        cin >> P[i+1];
        P[i+1] += P[i];  // cumulative sum
    }

    vector<pair<int, int>> sorted_X;
    rep(i, N){
        sorted_X.emplace_back(X[i], i);
    }
    sort(all(sorted_X));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        // Find first X >= L
        auto it_l = lower_bound(all(sorted_X), make_pair(L, 0));
        // Find first X > R
        auto it_r = upper_bound(all(sorted_X), make_pair(R, N));
        
        int l_idx = (it_l == sorted_X.end()) ? N : it_l->second;
        int r_idx = (it_r == sorted_X.end()) ? N : it_r->second;
        
        // Need to find the actual range of indices where X[i] is between L and R
        // The above approach might not give contiguous indices
        // So better to iterate through the sorted list and sum corresponding P values
        int sum = 0;
        for (auto it = it_l; it != it_r; ++it) {
            int idx = it->second;
            sum += P[idx+1] - P[idx];
        }
        cout << sum << endl;
    }
}