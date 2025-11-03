#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, q;
ll a[MAXN];

// Function to find the k-th smallest distance from point b to any A_i
ll solveQuery(ll b, int k) {
    // Create vector of distances from b to each a[i]
    vector<ll> dists;
    for (int i = 0; i < n; i++) {
        dists.push_back(abs(a[i] - b));
    }
    
    // Sort and return k-th smallest (1-indexed)
    sort(dists.begin(), dists.end());
    return dists[k - 1];
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Process each query
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        cout << solveQuery(b, k) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}