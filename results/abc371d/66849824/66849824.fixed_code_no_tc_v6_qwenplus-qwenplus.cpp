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
    vector<ll> P(N+1);
    vector<ll> X(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Create a sorted vector of pairs (X[i], i)
    vector<pair<ll, int>> sorted_X(N);
    for (int i = 0; i < N; ++i) {
        sorted_X[i] = {X[i], i};
    }
    sort(all(sorted_X));

    // Extract just the indices in sorted order
    vector<int> prefix_sum_indices(N+1);
    prefix_sum_indices[0] = 0;
    for (int i = 0; i < N; ++i) {
        prefix_sum_indices[i+1] = sorted_X[i].second;
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;

        // Binary search to find range of elements between L and R inclusive
        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (sorted_X[mid].first < L) left = mid + 1;
            else right = mid;
        }
        int l_idx = left;

        left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;
            if (sorted_X[mid].first <= R) left = mid + 1;
            else right = mid;
        }
        int r_idx = left;

        // Calculate prefix sum
        int ans = P[prefix_sum_indices[r_idx]] - P[prefix_sum_indices[l_idx]];
        cout << ans << endl;
    }
}