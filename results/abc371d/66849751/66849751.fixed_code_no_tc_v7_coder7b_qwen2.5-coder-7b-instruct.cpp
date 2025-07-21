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
    map<int, int> x_to_ptr;
    rep(i, N){
        x_to_ptr[X[i]] = i; // Ensure that each key is unique and corresponds to the last occurrence of X[i]
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        if (X_l == x_to_ptr.begin()) {
            l = -1; // Set l to -1 if there's no element less than L
        } else {
            --X_l; // Move one step back to get the largest element less than or equal to L
            l = (*X_l).second;
        }

        if (X_r != x_to_ptr.end()) {
            r = (*X_r).second; // Set r to the current element since upper bound points to the first element greater than R
        } else {
            r = N; // Set r to N if there's no element greater than R
        }

        int ans = P[r+1] - P[l+1]; // Adjust indices as P array has an extra element at index 0
        cout << ans << endl;
    }
}