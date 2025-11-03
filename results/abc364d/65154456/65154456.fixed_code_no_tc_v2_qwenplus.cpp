#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, q;
ll a[MAXN];

// Function to find the k-th smallest distance from point b to any point in array a
ll solve_query(ll b, int k) {
    // Create vector of distances from b to each a[i]
    vector<ll> dists;
    for (int i = 0; i < n; i++) {
        dists.push_back(abs(a[i] - b));
    }
    
    // Partial sort to get k-th smallest element
    nth_element(dists.begin(), dists.begin() + k - 1, dists.end());
    return dists[k - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        cout << solve_query(b, k) << '\n';
    }
    
    return 0;
}