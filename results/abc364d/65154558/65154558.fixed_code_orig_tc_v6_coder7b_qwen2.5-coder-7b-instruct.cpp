#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n); b.resize(q);
    
    // Read coordinates of points A and B
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q; ++i) cin >> b[i];
    
    // Sort the coordinates of points A
    sort(a.begin(), a.end());
    
    // For each query
    for(int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        
        // Calculate distances from point x to all points in A
        vector<int> dists;
        for(auto& p : a) dists.push_back(abs(p - x));
        
        // Sort these distances
        sort(dists.begin(), dists.end());
        
        // Output the k-th smallest distance
        cout << dists[k-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}