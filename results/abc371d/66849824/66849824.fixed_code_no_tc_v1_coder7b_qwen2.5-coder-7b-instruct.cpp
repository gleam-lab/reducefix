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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    
    // Create a map to store the cumulative sum of people up to each position
    map<int, ll> cumsum;
    rep(i, N) {
        cumsum[X[i]] = P[i + 1];
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        
        // Find the smallest key greater than or equal to L
        auto it_l = cumsum.lower_bound(L);
        // Find the smallest key strictly greater than R
        auto it_r = cumsum.upper_bound(R);
        
        // If there is no such key, it means R is less than any key in the map
        if (it_r == cumsum.begin()) {
            cout << 0 << endl;
            continue;
        }
        
        // Adjust the iterator for upper_bound to point to the correct element
        --it_r;
        
        // Calculate the result as the difference between the cumulative sums
        ll ans = it_r->second - (it_l != cumsum.begin() ? prev(it_l)->second : 0);
        cout << ans << endl;
    }
}