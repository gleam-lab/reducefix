#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n), b(q);
    vector<int> k(q);
    
    // Read coordinates of points A
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read coordinates of points B and their respective k values
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    // Sort the coordinates of points A
    sort(a.begin(), a.end());
    
    // For each point B_j, find the k_j-th closest point A_i
    for (int i = 0; i < q; ++i) {
        int target = b[i];
        int pos = lower_bound(a.begin(), a.end(), target) - a.begin();
        
        // Calculate the k_j-th closest point
        int index = pos + k[i] - 1;
        if (index >= n) index = n - 1; // Ensure it doesn't go out of bounds
        
        // Calculate the distance
        long long dist = abs(a[index] - target);
        
        // Output the result
        cout << dist << '\n';
    }
    
    return 0;
}