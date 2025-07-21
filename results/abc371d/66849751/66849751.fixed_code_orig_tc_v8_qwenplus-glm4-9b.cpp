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
    map<int, int> x_to_idx; // Changed key to int to store the index of X[i]
    rep(i, N){
        x_to_idx.emplace(i, X[i]); // Store the index as the key
    }
    // for (const auto& [k, v] : x_to_idx){
    //     cout << "X_i is " << k << " and i is " << v << endl;
    // }

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R, l, r;
        cin >> L >> R;
        auto X_l = x_to_idx.lower_bound(L);
        auto X_r = x_to_idx.upper_bound(R);
        if (X_l == x_to_idx.begin() && X_l->second < L){ // If the first element is less than L
            l = -1; // Set l to a value that is out of the valid range
        }else{
            l = (X_l == x_to_idx.begin()) ? 0 : (X_l->second - 1);
        }
        if (X_r == x_to_idx.end() || X_r->second > R){ // If the last element is greater than R
            r = N; // Set r to the last index
        }else{
            r = X_r->second;
        }
        // cout << "l is " << l << " and r is " << r << endl;
        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}