#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void solve() {
    int n, q;
    cin >> n >> q;
    
    // Read coordinates of points A_i
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Process each query
    for(int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        
        // Calculate distances from point B_j to all points A_i
        vector<int> distances(n);
        for(int i = 0; i < n; ++i) {
            distances[i] = abs(a[i] - b);
        }
        
        // Sort the distances
        sort(distances.begin(), distances.end());
        
        // Find the k-th smallest distance
        cout << distances[k - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}