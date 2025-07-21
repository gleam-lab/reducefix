#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], prefixSum[200005]; // prefixSum will store cumulative sum of p[] up to each index.
int main(){
    cin >> n; // Read number of elements in x[] and p[] (n)
    for(int i = 1; i <= n; i++){ // Read elements of x[] (they are not used in this problem)
        cin >> x[i]; // You can ignore these values since they are not used in any calculations.
    }
    // Calculate and store cumulative sum of p[] in prefixSum[] (This will be used for range queries)
    for(int i = 1; i <= n; i++){ // Start from 1 since index 0 is not used for prefix sum.
        prefixSum[i] = prefixSum[i - 1] + p[i]; // Calculate cumulative sum and store it in prefixSum[].
    }
    cin >> q; // Read number of queries (q) to perform.
    while(q--){ // For each query...
        int L, R; // Read left and right indices for the range query. (Note: Since indices start from 1 in this code, adjust as needed if indices start from 0 in your problem.)
        cin >> L >> R; // Adjust indices if necessary. e.g., if input is [L=1, R=n], adjust to [L-1, R-1] for proper indexing.
        // Calculate the difference in cumulative sums for the range query. (This will give us the sum of p[] values in the range.)
        cout << (prefixSum[R] - prefixSum[L - 1]) << endl; // Output the result. Note that L-1 is used for proper indexing since we start counting from 1. Adjust if necessary. 
    } // End while loop for queries. Note that we do not need to process or modify p[] again after initial calculation of prefixSum[]. We only need to access it for range queries. 
} // End main() function. Note that this solution assumes that p[] is sorted and that L and R represent valid indices within the array. Adjustments may be needed if these assumptions are not valid in your specific case.