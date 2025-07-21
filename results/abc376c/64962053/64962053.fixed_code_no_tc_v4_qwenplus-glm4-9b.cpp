#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> toy_sizes(n);
    std::vector<int> box_sizes(n - 1);

    for (int i = 0; i < n; ++i) {
        std::cin >> toy_sizes[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        std::cin >> box_sizes[i];
    }

    // We need to find the minimum size of the box x that can be purchased
    // such that all toys can be stored in the boxes (including the new one)
    // which means the x must be at least as large as the largest toy size.
    int minimum_box_size = *max_element(toy_sizes.begin(), toy_sizes.end());

    // We need to ensure that the newly purchased box can fit the largest toy
    // and that all other toys can fit into the pre-existing boxes or the new box.
    bool possible = true;
    for (int i = 0; i < n - 1; ++i) { // Compare with all pre-existing boxes
        if (toy_sizes[i] > box_sizes[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        std::cout << minimum_box_size << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}