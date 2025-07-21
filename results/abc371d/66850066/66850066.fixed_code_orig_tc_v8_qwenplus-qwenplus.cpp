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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    // Coordinate compression
    vector<int> sorted_X = X;
    sort(sorted_X.begin(), sorted_X.end());
    map<int, int> x_to_idx;
    rep(i, N) {
        x_to_idx[sorted_X[i]] = i + 1; // 1-based indexing for binary search convenience
    }

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;

        // Binary search for lower bound and upper bound
        int left = lower_bound(sorted_X.begin(), sorted_X.end(), L) - sorted_X.begin();
        int right = upper_bound(sorted_X.begin(), sorted_X.end(), R) - sorted_X.begin();

        // Sum from index left to right in prefix sum array
        ll ans = P[right] - P[left];
        cout << ans << endl;
    }
}