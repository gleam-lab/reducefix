#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements
    
    // Create a sorted array for sum calculation
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> sum[i]; // Input elements for each position
    }
    
    // Initialize variables for querying lower and upper bounds
    int l = 0, r = n; // Assuming the query range is within the array bounds
    int query_sum = sum[r - 1]; // Query sum at the end of the range
    
    // Main logic to calculate difference between two sums
    while (true) {
        int L, R; // Current query range and expected output
        cin >> L >> R; // Input query range and expected output difference
        
        // Find the index of the element in the sorted array
        int index = lower_bound(sum.begin(), sum.end(), L) - sum.begin() + 1; // Using lower_bound to find the index within bounds
        
        // Calculate the difference between sums at the start and end of the range
        int diff = query_sum - sum[index]; // The difference between two sums in the query range
        
        // Output the result if it's within the expected range
        if (diff >= 0 && diff <= query_sum) {
            cout << diff << endl; // Output the result as requested by the question
            break; // Exit loop if the result is within the expected range
        }
    }
    return 0; // Return 0 to indicate successful completion of the program
}