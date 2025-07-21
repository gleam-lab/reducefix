#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    // Read the array elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the array to facilitate removal of elements
    sort(A.begin(), A.end());
    
    // The initial maximum value is A[N-1] and the minimum is A[0]
    int max_val = A[N-1], min_val = A[0];
    int min_diff = max_val - min_val;
    
    // We need to consider the removal of K elements, which might change the min and max values
    // The minimum and maximum after removal would be in the remaining elements, which are A[K] to A[N-1]
    // We iterate over each possible size of removed elements (from 0 to min(K, N-1)) and calculate the difference
    for (int remove_count = 0; remove_count <= min(K, N-1); ++remove_count) {
        // Calculate the new min and max after removing 'remove_count' elements
        int new_max = INT_MIN, new_min = INT_MAX;
        for (int j = remove_count; j < N; ++j) {
            new_max = max(new_max, A[j]);
        }
        for (int j = 0; j < remove_count; ++j) {
            new_min = min(new_min, A[j]);
        }
        
        // Update the minimum difference found so far
        min_diff = min(min_diff, new_max - new_min);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}