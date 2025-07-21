#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

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
    
    vector<pair<ll, int>> x_to_ptr(N);
    rep(i, N) {
        x_to_ptr[i] = {X[i], i};
    }
    sort(x_to_ptr.begin(), x_to_ptr.end());
    
    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto left_idx = lower_bound(x_to_ptr.begin(), x_to_ptr.end(), make_pair(L, INT_MAX)) - x_to_ptr.begin();
        auto right_idx = upper_bound(x_to_ptr.begin(), x_to_ptr.end(), make_pair(R, INT_MIN)) - x_to_ptr.begin() - 1;
        
        if (left_idx == N || right_idx < 0 || x_to_ptr[left_idx].first > R || x_to_ptr[right_idx].first < L) {
            cout << 0 << endl;
        } else {
            cout << P[x_to_ptr[right_idx].second + 1] - P[x_to_ptr[left_idx].second + 1] << endl;
        }
    }
    return 0;
}