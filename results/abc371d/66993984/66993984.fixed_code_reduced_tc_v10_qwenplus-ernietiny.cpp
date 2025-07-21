#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array
    
    // Create a map to store the sum of each element
    map<int, int> sumMap;
    for (int i = 1; i <= n; ++i) {
        sumMap[i] = sum[i - 1]; // Initialize the sum of the current element
    }
    
    // Read the elements and their corresponding values
    int x[n]; // Array to store the elements
    for (int i = 0; i < n; ++i) {
        cin >> x[i]; // Read the elements
    }
    
    // Calculate the sum of the elements in the array
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += sumMap[x[i]]; // Update the sum of the elements in the map
    }
    
    // Process the query cases
    while (true) {
        int L, R; // Query cases: left and right indices to find the difference between sum and target value
        cin >> L >> R; // Read the query indices
        int targetValue = totalSum - sumMap[R]; // Calculate the target value to be compared with the sumMap[R]
        cout << targetValue << endl; // Output the result
        sumMap[R] -= targetValue; // Update the sumMap[R] to reflect the difference between actual sum and target value
    }
}