#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements
    
    // Initialize the sum array with the initial values of the elements
    for (int i = 0; i < n; ++i) {
        sum[i] = x[i]; // Assuming x[i] represents the element value
    }
    
    // Read the query values and their indices
    int q;
    cin >> q; // Number of queries
    vector<pair<int, int>> queries; // To store the indices and query values
    for (int i = 0; i < q; ++i) {
        int l, r; // Indices of the elements to be compared
        cin >> l >> r; // Elements to compare their indices
        queries.push_back({l, r}); // Adding the query pair to the vector
    }
    
    // Sort the indices in ascending order to handle queries efficiently
    sort(queries.begin(), queries.end());
    
    // Calculate the sum of differences between consecutive elements
    for (int i = 1; i < n; ++i) {
        sum[i] -= sum[i - 1]; // Subtracting the previous sum value from current element value
    }
    
    // Perform queries and output the result
    for (const auto& query : queries) {
        int expectedDifference = query.second - sum[query.first]; // Expected difference between query indices and sum array
        cout << expectedDifference << endl; // Outputting the expected difference if positive or printing '-' for negative values if needed
    }
    
    return 0; // Returning 0 to indicate successful completion of the program
}