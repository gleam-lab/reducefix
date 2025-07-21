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
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> X(N), P(N+1, 0);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    vector<pair<ll, int>> sortedX;
    for (int i = 0; i < N; ++i) {
        ll x;
        cin >> x;
        sortedX.emplace_back(X[i], i);
        P[i+1] = P[i] + x;
    }

    sort(sortedX.begin(), sortedX.end());

    // For a given value, find the first index where X >= L using lower_bound
    // We only need to map X values to their indices in the sorted array
    vector<ll> sortedValues;
    for (const auto& p : sortedX) {
        sortedValues.push_back(p.first);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        // Find lower bound of L and upper bound of R
        int left = lower_bound(sortedValues.begin(), sortedValues.end(), L) - sortedValues.begin();
        int right = upper_bound(sortedValues.begin(), sortedValues.end(), R) - sortedValues.begin();

        // Prefix sum from left to right
        cout << P[right] - P[left] << "\n";
    }

    return 0;
}