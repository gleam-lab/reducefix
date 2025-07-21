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
    cin.tie(0);
    
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

    // Build prefix sum array with coordinate compression support
    vector<pair<ll, int>> sorted_X(N);
    rep(i, N) sorted_X[i] = {X[i], i};
    sort(all(sorted_X));

    // For binary search boundaries
    vector<ll> sorted_values(N);
    rep(i, N) sorted_values[i] = sorted_X[i].first;

    int Q;
    cin >> Q;
    rep(q, Q){
        ll L, R;
        cin >> L >> R;

        // Find the first index where X[i] >= L using lower_bound
        int left = lower_bound(sorted_values.begin(), sorted_values.end(), L) - sorted_values.begin();

        // Find the first index where X[i] > R using upper_bound
        int right = upper_bound(sorted_values.begin(), sorted_values.end(), R) - sorted_values.begin();

        // Sum from prefix sum array
        ll ans = P[right] - P[left];
        cout << ans << endl;
    }
}