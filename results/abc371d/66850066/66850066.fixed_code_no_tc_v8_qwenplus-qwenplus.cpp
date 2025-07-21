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
    vector<ll> P(N + 1, 0);
    vector<int> X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Create a sorted vector of pairs (X[i], i) for efficient range queries
    vector<pair<int, int>> x_with_index(N);
    rep(i, N) {
        x_with_index[i] = {X[i], i};
    }
    sort(all(x_with_index));

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Binary search to find the range of indices where X[i] is in [L, R]
        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x_with_index[mid].first < L) left = mid + 1;
            else right = mid;
        }
        int l = left;

        left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x_with_index[mid].first <= R) left = mid + 1;
            else right = mid;
        }
        int r = left;

        // Map back to original prefix sum indices and compute result
        int ans = P[r] - P[l];
        cout << ans << endl;
    }
}