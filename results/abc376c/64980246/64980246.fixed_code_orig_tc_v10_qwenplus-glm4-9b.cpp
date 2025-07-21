#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n), b(n - 1);
    
    for (ll &i : a) std::cin >> i;
    for (ll &i : b) std::cin >> i;
    
    // Sort the toy sizes and the box sizes in ascending order.
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    ll x = 0; // x will store the minimum size of the box that can store all toys.
    ll j = 0; // j is the index for the toy sizes.
    
    // Iterate over the toy sizes and the box sizes.
    for (int i = 0; i < n - 1; ++i) {
        // While there are toys that can be placed in an existing box `b[j]`.
        while (j < n && a[j] <= b[i]) {
            j++; // Move to the next toy size.
        }
        
        // If we have placed all toys, we found the minimum size `x` for the new box.
        if (j == n) {
            std::cout << b[i] << std::endl;
            return;
        }
        
        // Select the larger of the current box size or the toy size that comes after the last placed toy.
        x = std::max(x, a[j]);
    }
    
    // If all toys are placed in existing boxes, x will be the size of the last box used.
    std::cout << x << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}