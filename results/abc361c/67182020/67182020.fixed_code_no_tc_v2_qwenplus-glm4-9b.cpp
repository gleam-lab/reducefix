#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    // Read the array elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // If K is the same as N, the answer is always 0 because we cannot remove any elements
    if (K == N) {
        cout << 0 << endl;
        return 0;
    }
    
    // Edge case: if K is 1, we should remove the maximum element
    if (K == 1) {
        cout << *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) << endl;
        return 0;
    }
    
    // Sort the array to easily find the minimum and maximum values
    sort(A.begin(), A.end());
    
    // Calculate the minimum possible value of the maximum minus the minimum value
    // after removing K elements
    int minMaxDiff = INT_MAX;
    
    // We need to consider removing K elements in such a way that we maximize the difference
    // between the remaining maximum and minimum elements.
    // We can do this by removing elements from the ends of the sorted array first.
    
    // Case 1: Remove elements from the beginning and end
    minMaxDiff = min(minMaxDiff, A[N - 1 - K] - A[K]);
    
    // Case 2: Remove elements from the beginning, but not all the way to the middle
    if (K < N / 2) {
        minMaxDiff = min(minMaxDiff, A[N - 1 - (K + 1)] - A[K + 1]);
    }
    
    // Case 3: Remove elements from the end, but not all the way to the middle
    if (K < N / 2) {
        minMaxDiff = min(minMaxDiff, A[N - 1 - K] - A[K]);
    }
    
    // Case 4: Remove elements from the middle
    if (K >= N / 2) {
        minMaxDiff = min(minMaxDiff, A[N - 1 - K] - A[N / 2]);
    }
    
    cout << minMaxDiff << endl;
    
    return 0;
}