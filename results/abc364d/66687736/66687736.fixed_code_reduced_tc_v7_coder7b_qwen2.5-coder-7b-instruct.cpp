#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int query = 0; query < q; ++query) {
        int b, k;
        cin >> b >> k;
        
        // Calculate distances from B to all points A
        vector<int> distances;
        for (int ai : a) {
            distances.push_back(abs(ai - b));
        }
        
        // Sort the distances
        sort(distances.begin(), distances.end());
        
        // Output the k-th smallest distance
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}