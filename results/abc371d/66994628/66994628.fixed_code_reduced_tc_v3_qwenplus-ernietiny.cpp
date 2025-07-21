#include <iostream>

int main() {
    int n;
    std::cin >> n; // Input the number of elements.
    std::vector<int> x(n + 1), p; // Allocate memory for x and p arrays.
    std::cin >> p; // Read the numbers associated with each element.

    for (int i = 1; i <= n; ++i) { // Iterate over the elements.
        x[i] = static_cast<int>(rand() % INT_MAX); // Randomly generate x array elements.
    }

    int sum = 0; // Initialize sum variable.
    std::cin >> sum; // Read the final sum.

    std::vector<int> modified_x, modified_sum; // Modified arrays for x and sum.
    std::cin >> modified_x >> modified_sum; // Read modified elements and sum.

    int q; // Input the number of queries.
    std::cin >> q; // Read the number of queries.

    while (q--) { // Process each query.
        int l, r; // Input the left and right bounds of the query range.
        std::cin >> l >> r; // Read the bounds of the query range.
        l = std::lower_bound(x.begin(), x.end(), l) - x.begin() + 1; // Calculate the index of the element in modified x array.
        r = std::upper_bound(modified_x.begin(), modified_x.end(), r) - modified_x.begin(); // Calculate the range of elements in the modified array.
        // Calculate the difference between modified sum and original sum.
        int diff = static_cast<int>(std::abs(modified_sum[r - 1] - sum)); // The expected output difference is stored in diff.
        std::cout << diff << std::endl; // Output the expected output difference if it is within the range [0, N-1].
    }

    return 0; // Return 0 to indicate successful completion of the program.
}