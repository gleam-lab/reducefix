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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    vector<ll> P(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    // Build prefix sum and coordinate compression
    vector<int> sorted_X = X;
    sort(sorted_X.begin(), sorted_X.end());
    map<int, int> compressed;
    int idx = 0;
    for (int x : sorted_X) {
        if (!compressed.count(x)) {
            compressed[x] = idx++;
        }
    }

    // Build prefix sums for each unique X coordinate
    vector<ll> prefix_sum(idx + 1, 0);
    for (int i = 0; i < N; ++i) {
        int pos = compressed[X[i]];
        prefix_sum[pos + 1] += P[i + 1] - P[i];  // Add contribution to the prefix sum
    }

    // Build prefix cumulative sum
    for (int i = 1; i <= idx; ++i) {
        prefix_sum[i] += prefix_sum[i - 1];
    }

    // Coordinate compression helper
    auto get_prefix_sum = [&](int x) {
        auto it = upper_bound(sorted_X.begin(), sorted_X.end(), x);
        if (it == sorted_X.begin()) return 0LL;
        int pos = it - sorted_X.begin();
        return prefix_sum[pos];
    };

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        ll total = get_prefix_sum(R) - get_prefix_sum(L - 1);
        cout << total << "\n";
    }

    return 0;
}