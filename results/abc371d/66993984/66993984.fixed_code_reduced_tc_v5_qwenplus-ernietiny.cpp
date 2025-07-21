#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array
    
    // Create a map to store the sum of each element for easier lookup
    map<int, int> sumMap;
    
    // Populate the map with the given values
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // Elements in the array
        sumMap[x[i]] = sumMap[x[i-1]] + x[i]; // Update the sum for each element
    }
    
    // Process each query case
    while (true) {
        int L, R; // Query cases
        cin >> L >> R; // Elements to find the difference between their sum and the target value
        int target = sumMap[R] - sumMap[L]; // Calculate the difference between the target and the current element's sum
        cout << target << endl; // Output the result
        sumMap[R] -= target; // Update the element's sum after processing each query case
    }
    return 0; // Return 0 to indicate successful completion of the program
}