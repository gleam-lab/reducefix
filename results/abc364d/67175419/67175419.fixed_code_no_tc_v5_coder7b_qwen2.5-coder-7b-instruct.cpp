#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to find the k-th smallest distance
int findKthSmallestDistance(vector<int>& distances, int k) {
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // Read input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    vector<int> distances(n);
    
    while (m--) {
        int b, k;
        cin >> b >> k;
        
        // Calculate distances for the current B_j
        for (int i = 1; i <= n; i++) {
            distances[i - 1] = abs(b - a[i]);
        }
        
        // Find the k-th smallest distance
        int result = findKthSmallestDistance(distances, k);
        
        // Output the result
        cout << result << "\n";
    }
    
    return 0;
}