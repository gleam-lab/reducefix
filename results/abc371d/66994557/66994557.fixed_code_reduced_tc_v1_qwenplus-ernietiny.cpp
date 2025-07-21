#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements
    
    // Create a sorted array for sum calculation
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> sum[i]; // Input elements for each element
    }
    
    // Sort the array to handle range queries efficiently
    sort(sum.begin(), sum.end());
    
    int q; // Number of queries
    cin >> q; // Number of queries to process
    
    while (q--) { // Process each query
        int L, R; // Left and Right indices for range query
        cin >> L >> R; // Input the left and right indices of the range to be calculated
        // Calculate the difference between the sum at the target index and the sum at the previous index
        int targetSum = sum[R] - sum[L - 1]; // The target sum is the difference between the target element and the previous element
        cout << targetSum << endl; // Output the result
    }
    return 0; // Return 0 to indicate successful completion of the program
}