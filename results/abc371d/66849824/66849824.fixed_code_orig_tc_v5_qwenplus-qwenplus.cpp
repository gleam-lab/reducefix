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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N + 1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Build prefix sum array and coordinate compression
    vector<ll> sorted_X = X;
    sort(sorted_X.begin(), sorted_X.end());

    // For each query L and R, find the indices in X that are within [L, R]
    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        // Find first index where X[i] >= L
        int left = lower_bound(sorted_X.begin(), sorted_X.end(), L) - sorted_X.begin();
        // Find first index where X[i] > R
        int right = upper_bound(sorted_X.begin(), sorted_X.end(), R) - sorted_X.begin();

        // Sum of P from 'left' to 'right - 1'
        if (left < right) {
            cout << P[right] - P[left] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}