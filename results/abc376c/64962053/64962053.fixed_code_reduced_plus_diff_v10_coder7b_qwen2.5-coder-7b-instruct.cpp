#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    for(int i = 0; i < n-1; ++i) {
        std::cin >> b[i];
    }
    
    // Sort both arrays
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    // Check if there exists a valid box size
    for(int i = 0; i < n-1; ++i) {
        if(a[i+1] > b[i]) {
            std::cout << b[i] << std::endl;
            return 0;
        }
    }
    
    // If no valid box size is found
    std::cout << "-1" << std::endl;
    
    return 0;
}