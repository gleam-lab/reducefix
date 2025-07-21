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

    int left = 0, right = 0;
    int bestMinDiff = INT_MAX;
    
    // Iterate through the sorted array
    for (int i = 0; i < N - K; ++i) {
        // Expand the window to the left and right
        while (right < N - K && A[right + 1] - A[right] <= K) {
            right++;
        }
        
        // Calculate the difference between the maximum and minimum elements in the window
        int currentMin = A[i];
        int currentMax = A[right];
        int currentDiff = currentMax - currentMin;
        
        // Update the best minimum difference if the current one is smaller
        bestMinDiff = min(bestMinDiff, currentDiff);
    }
    
    cout << bestMinDiff << endl;
    return 0;
}