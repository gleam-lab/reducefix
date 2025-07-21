#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

const int MAX = 2e9 + 7;

void solve() {
    int n, q; cin >> n >> q;
    
    // Store coordinates of points A_i
    vl a(n);
    rep(i, n) cin >> a[i];
    
    // Store coordinates of points B_j and their corresponding k_j
    vl b(q), k(q);
    rep(i, q) cin >> b[i] >> k[i];
    
    // Create a sorted list of all unique distances from B_j to any A_i
    set<ll> dists;
    rep(j, q) {
        rep(i, n) {
            ll d = abs(a[i] - b[j]);
            dists.insert(d);
        }
    }
    
    // Convert set to vector for binary search
    vl sorted_dists(dists.begin(), dists.end());
    
    // Answer each query
    rep(j, q) {
        // Find the k_j-th smallest distance using binary search
        auto it = sorted_dists.begin();
        advance(it, k[j] - 1);
        cout << *it << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; // For multiple test cases
    // cin >> t;
    while(t--) solve();
    return 0;
}