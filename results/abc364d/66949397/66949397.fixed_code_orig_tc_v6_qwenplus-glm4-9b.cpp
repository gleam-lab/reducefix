#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int main() {
    ll n, q;
    std::cin >> n >> q;
    
    std::vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    while (q--) {
        ll b, k;
        std::cin >> b >> k;
        
        // Sorting to find the k-th closest distance
        std::vector<ll> distances;
        for (ll i = 0; i < n; ++i) {
            distances.push_back(std::abs(a[i] - b));
        }
        
        // Sorting the distances to get them in ascending order
        std::sort(distances.begin(), distances.end());
        
        // The k-th closest distance is the k-th smallest distance
        ll result = distances[k - 1];
        
        // Output the result
        std::cout << result << std::endl;
    }
    
    return 0;
}