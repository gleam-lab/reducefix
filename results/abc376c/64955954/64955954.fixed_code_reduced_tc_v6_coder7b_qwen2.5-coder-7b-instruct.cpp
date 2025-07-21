#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> va(n), vb(n - 1);
    
    for (int i = 0; i < n; ++i)
        std::cin >> va[i];
    
    for (int i = 0; i < n - 1; ++i)
        std::cin >> vb[i];
    
    // Sort the arrays
    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());
    
    // Check if the largest toy can fit into any of the existing boxes
    for (int i = 0; i < n - 1; ++i) {
        if (va[n - 1] <= vb[i]) {
            std::cout << va[n - 1] << std::endl;
            return 0;
        }
    }
    
    // If the largest toy cannot fit into any of the existing boxes,
    // check if it can fit into a new box of size equal to the largest toy
    if (va[n - 1] > vb[n - 2]) {
        std::cout << va[n - 1] << std::endl;
        return 0;
    } else {
        std::cout << -1 << std::endl;
        return 0;
    }
}