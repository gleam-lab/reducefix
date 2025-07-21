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
    vector<int> P(N+1);
    vector<ll> X(N);
    
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    // Create a sorted vector of pairs (X[i], prefix sum P[i+1])
    vector<pair<ll, int>> sorted_x_psum;
    rep(i, N) {
        sorted_x_psum.emplace_back(X[i], P[i+1]);
    }
    sort(all(sorted_x_psum));

    // For binary search, we'll use the sorted vector directly
    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        
        // Find left bound using lower_bound on sorted X values
        auto left = lower_bound(sorted_x_psum.begin(), sorted_x_psum.end(), make_pair(L, 0));
        int sum_left = 0;
        if (left != sorted_x_psum.begin()) {
            sum_left = prev(left)->second;
        }
        
        // Find right bound using upper_bound on sorted X values
        auto right = upper_bound(sorted_x_psum.begin(), sorted_x_psum.end(), make_pair(R, numeric_limits<int>::max()));
        int sum_right = 0;
        if (right != sorted_x_psum.begin()) {
            sum_right = prev(right)->second;
        }
        
        cout << sum_right - sum_left << endl;
    }

    return 0;
}