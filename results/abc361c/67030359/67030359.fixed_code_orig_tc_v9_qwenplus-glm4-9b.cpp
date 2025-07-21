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
    
    // Sort the array to easily find ranges
    sort(A.begin(), A.end());
    
    // Find the minimum range after removing K elements
    int l = 0, r = 0, minRange = INT_MAX;
    while (r < N) {
        int windowSize = r - l + 1;
        // If the window size is more than K, move the left pointer to shrink the window
        if (windowSize > K) {
            l++;
        } else { // If the window size is K or less, check if it's the minimum range
            minRange = min(minRange, A[r] - A[l]);
            r++;
        }
    }
    
    cout << minRange << endl;
    return 0;
}