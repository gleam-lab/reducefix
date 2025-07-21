#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n - 1);

    for(int i = 0; i < n; ++i) 
        std::cin >> a[i];
    
    for(int i = 0; i < n - 1; ++i) 
        std::cin >> b[i];

    // Sort both arrays to facilitate binary search
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    // Iterate over all boxes
    for(int x = 1; x <= 1e9; ++x) {
        bool valid = true;

        // Check if we can place each toy into a box
        for(int i = 0; i < n && valid; ++i) {
            // Find the first box with size >= toy size
            auto it = std::lower_bound(b.begin(), b.end(), a[i]);
            
            // If no suitable box is found, mark as invalid
            if(it == b.end() || *it < a[i]) {
                valid = false;
            } else {
                // Remove used box
                b.erase(it);
            }
        }

        // If we successfully placed all toys, return the current box size
        if(valid) {
            std::cout << x << std::endl;
            return 0;
        }

        // Re-add all boxes for next iteration
        b.insert(b.end(), n - 1, 1);
    }

    // If no valid box size was found, output -1
    std::cout << -1 << std::endl;
    return 0;
}