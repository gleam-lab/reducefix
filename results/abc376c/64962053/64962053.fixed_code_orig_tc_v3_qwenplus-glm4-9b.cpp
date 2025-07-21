#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> va(n), vb(n - 1);
    
    for (int i = 0; i < n; i++) {
        std::cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        std::cin >> vb[i];
    }
    
    // Sort the toy sizes and the given box sizes
    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());
    
    // Check if all toys fit into the given boxes
    for (int i = 0; i < n; i++) {
        // If the toy is larger than all given boxes, we need to buy a new one
        if (va[i] > vb[i]) {
            // The smallest possible new box that can fit the toy is va[i]
            std::cout << va[i] << std::endl;
            return 0;
        }
    }
    
    // If all toys fit into the given boxes, no new box is needed
    std::cout << -1 << std::endl;
    return 0;
}