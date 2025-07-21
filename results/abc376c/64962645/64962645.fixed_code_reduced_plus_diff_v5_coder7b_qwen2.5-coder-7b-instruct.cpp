#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> va(n), vb(n);
    
    // Read toy sizes
    for (int i = 0; i < n; ++i)
        std::cin >> va[i];
    
    // Read box sizes
    for (int i = 0; i < n - 1; ++i)
        std::cin >> vb[i];
    
    // Sort toy sizes and box sizes
    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());
    
    // Check if it's possible to place all toys in separate boxes
    bool possible = true;
    for (int i = 0; i < n && possible; ++i) {
        auto it = std::lower_bound(vb.begin(), vb.end(), va[i]);
        if (it == vb.end()) {
            possible = false;
        } else {
            vb.erase(it); // Mark the box as used
        }
    }
    
    // Determine the result
    if (!possible) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << va[n - 1] << std::endl;
    }
    
    return 0;
}