#include <iostream>

int main() {
    int n;
    std::cin >> n; // Input the number of elements

    // Allocate memory for sum array and sort the elements for quick retrieval
    std::vector<int> sum(n + 1);
    std::sort(sum.begin(), sum.end());

    // Read input values
    int x[n]; // Assuming x is an array of integers to store elements
    int p[n]; // Similarly, p represents the partial sums

    // Process the input and calculate the result
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> p[i]; // Read the element and partial sum
        sum[p[i]] -= x[i]; // Update the partial sum for the current element
    }

    // Process the query case
    int query; // Input the query value
    std::cin >> query; // Read the query value
    std::cout << sum[query] - sum[1] << std::endl; // Calculate and print the result

    return 0;
}