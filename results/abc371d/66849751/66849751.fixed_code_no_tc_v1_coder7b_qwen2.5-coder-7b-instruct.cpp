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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N), P(N+1);
    rep(i, N){
        cin >> X[i];
        cin >> P[i];
        P[i+1] = P[i] + P[i]; // Accumulate population up to each village
    }

    // Sort indices based on X values to handle duplicates correctly
    vector<int> ids(N);
    iota(all(ids), 0);
    sort(all(ids), [&](int i, int j){ return X[i] < X[j]; });

    map<int, int> x_to_ptr;
    rep(i, N){
        x_to_ptr.emplace(X[ids[i]], ids[i]);
    }

    int Q;
    cin >> Q;
    while(Q--){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        
        // Adjust pointers to include partial overlaps
        if (X_l != x_to_ptr.begin() && X_l->first > L) {
            --X_l;
        }
        if (X_r != x_to_ptr.end() && X_r->first <= R) {
            ++X_r;
        }

        if (X_l == x_to_ptr.end() || X_r == x_to_ptr.begin()) {
            cout << 0 << '\n';
            continue;
        }

        int l = X_l->second;
        int r = prev(X_r)->second;
        int ans = P[r+1] - P[l];
        cout << ans << '\n';
    }
}