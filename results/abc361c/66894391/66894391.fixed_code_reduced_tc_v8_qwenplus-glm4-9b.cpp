#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> A(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());
    
    long long minDiff = LLONG_MAX;
    int left = 0;
    
    // Iterate over each element considering it as the potential maximum of the new sequence B
    for (int i = 0; i < n; ++i) {
        // Move the left boundary to ensure we can remove exactly K elements to the left of the right boundary
        while (i - left + 1 > k) {
            left++;
        }
        
        // Calculate the difference between the current maximum and the smallest possible minimum
        if (i - left + 1 < k) { // If we cannot remove enough elements to the left, consider the start of the array
            minDiff = std::min(minDiff, A[i] - A[left]);
        } else {
            minDiff = std::min(minDiff, A[i] - A[left + 1]);
        }
    }
    
    std::cout << minDiff << std::endl;
    return 0;
}