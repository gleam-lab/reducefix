#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    
    // Read the toy sizes
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }
    
    // Find the maximum toy size
    int max_size = *std::max_element(A.begin(), A.end());
    
    // Output the result
    std::cout << max_size << std::endl;
    
    return 0;
}