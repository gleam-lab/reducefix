#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n), b(n);
    
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    for(int i = 1; i < n; ++i) {
        std::cin >> b[i];
    }
    
    // Sort the sizes of the toys and the boxes
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    // Check if the largest toy can fit into any of the available boxes
    if(a[n - 1] <= b[n - 1]) {
        std::cout << b[n - 1] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}