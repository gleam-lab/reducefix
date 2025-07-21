#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    // Initialize the minimum difference to a large number
    int min_diff = INT_MAX;
    
    // Iterate over all possible subarrays of length K
    for (int i = 0; i <= N - K; ++i) {
        // Calculate the difference between the max and min in the current subarray
        int current_diff = A[i + K - 1] - A[i];
        
        // Update the minimum difference found so far
        min_diff = min(min_diff, current_diff);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}