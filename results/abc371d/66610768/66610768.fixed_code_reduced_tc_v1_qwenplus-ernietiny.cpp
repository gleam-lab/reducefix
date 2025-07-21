#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array a
    vector<int> a(n+1); // Create an array of size n+1 to store the elements
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Read the elements from the array
    }
    
    // Function to find the maximum element in the array
    auto findMax = [](const vector<int>& arr) {
        auto it = max_element(arr.begin(), arr.end()); // Use max_element to find the maximum element
        return *it; // Return the maximum element
    };
    
    // Main logic to calculate the difference between two consecutive elements in the array
    int diff = findMax(a); // Initialize diff with the maximum element found
    int result = 0; // Initialize result to store the final answer
    for (int i = 2; i <= n; ++i) { // Iterate from index 2 to n (inclusive)
        int l_i = a.size() - i + 1; // Calculate the index of the leftmost element to compare with the current diff
        int r_j = diff - (i - 1); // Calculate the difference between current diff and the next element in the array
        result += r_j - diff; // Add the difference between the next element and the current diff to the result
    }
    
    // Output the result when given an input m
    if (m >= n) { // Check if we have more than one input case for outputting results
        cout << result << endl; // Output the final answer as the difference between consecutive elements in the array
    } else { // If there's only one input case, print a negative number if needed
        if (m == 0) { // If no more inputs, print a negative number for empty input case
            cout << -result << endl; // Output a negative number for the case where there's no further elements to compare with previous elements
        } else { // If there's only one input, it might be an error or an example input which is not considered in the given problem statement, so just print a blank line for it here as well. You can decide how to handle it based on your specific problem requirements.
        }
    }
    return 0; // Return 0 to indicate successful completion of the program.
}