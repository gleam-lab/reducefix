#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    if (K == 0) {
        // If K is 0, no elements are removed, so the difference is 0.
        cout << 0 << endl;
        return 0;
    }
    
    // Initial values for the minimum and maximum of the remaining sequence.
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    
    // Iterate over possible positions to remove elements.
    for (int i = 0; i <= N - K; ++i) {
        int left = A[i];
        int right = A[N - K - 1];
        
        // Calculate the possible minimum and maximum after removal.
        int possibleMin = min(A[i + 1], right);
        int possibleMax = max(A[i - 1], left);
        
        // Update the minimum and maximum values.
        minVal = min(minVal, possibleMin);
        maxVal = max(maxVal, possibleMax);
        
        // If the minimum possible value has been found, we can break early.
        if (maxVal - minVal == 0) {
            break;
        }
    }
    
    // Output the result.
    cout << maxVal - minVal << endl;
    
    return 0;
}