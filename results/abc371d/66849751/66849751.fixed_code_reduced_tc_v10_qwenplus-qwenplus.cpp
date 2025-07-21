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
    vector<ll> P(N+1), X(N);
    P[0] = 0;
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Create a vector of pairs to store both position and index
    vector<pair<ll, int>> x_index_pairs;
    rep(i, N) {
        x_index_pairs.emplace_back(X[i], i);
    }
    sort(all(x_index_pairs));

    // Build prefix sum array
    vector<ll> prefix_sum(N+1);
    prefix_sum[0] = 0;
    rep(i, N) {
        prefix_sum[i+1] = prefix_sum[i] + P[i+1];
    }

    // Build mapping from index to sorted position
    vector<int> index_to_sorted(N);
    rep(i, N) {
        index_to_sorted[x_index_pairs[i].second] = i;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        
        // Binary search to find the range
        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x_index_pairs[mid].first >= L) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int l = left;
        
        left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x_index_pairs[mid].first > R) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int r = left;
        
        ll ans = prefix_sum[r] - prefix_sum[l];
        cout << ans << endl;
    }
}