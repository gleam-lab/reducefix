#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        k--; // Make k zero-indexed
        
        // Generate all possible distances from A to B_j
        vector<ll> distances;
        for (int a : A) {
            distances.push_back(abs(a - b));
        }
        
        // Sort distances and find the k-th distance
        sort(distances.begin(), distances.end());
        cout << distances[k] << '\n';
    }
    
    return 0;
}