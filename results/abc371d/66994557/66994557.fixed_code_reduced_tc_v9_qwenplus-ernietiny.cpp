#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements
    
    // Create a sorted array for sum calculation
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> sum[i]; // Elements and their corresponding sums
    }
    
    // Helper function to find the index of element in sorted array
    vector<int>::iterator lower_bound = lower_bound(sum.begin(), sum.end(), x[1]); // Assuming x[1] is the first element to be modified
    
    // Calculate the difference between two adjacent elements in sorted array
    int diff = sum[upper_bound(sum.begin(), sum.end(), x[n]) - lower_bound - 1] - sum[lower_bound];
    
    // Process each query case separately
    for (int i = 0; i < n; ++i) {
        int L, R; // Query range boundaries
        cin >> L >> R; // Query ranges for specific values
        cout << diff << endl; // Output the difference as per query range
    }
    
    return 0;
}