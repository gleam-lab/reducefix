#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    
    // Reading the sizes of the toys
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    // Reading the sizes of the boxes
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }
    
    // Determine the largest toy size
    int max_a = *max_element(a.begin(), a.end());
    
    // Find the largest box size that is not smaller than max_a
    int min_x = INT_MAX;
    for (int box : b) {
        if (box >= max_a) {
            min_x = min(min_x, box);
        }
    }
    
    // Output the result
    if (min_x == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << min_x << std::endl;
    }
    
    return 0;
}