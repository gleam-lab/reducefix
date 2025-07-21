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
    
    // Sort the array to easily find the min and max by removing K elements
    sort(A.begin(), A.end());
    
    // If K is more than half the array, it's not possible to remove K elements
    // because we would have to remove all elements, resulting in an empty B.
    if (K > N / 2) {
        cout << 0 << endl;
        return 0;
    }

    // Now, to minimize the max of B - min of B, we want to remove elements
    // that are closest to the middle of the sorted array.
    int minMaxMinDiff = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        // Calculate the minimum of B without removing any elements, which is the first element
        int minB = A[0];
        // Calculate the maximum of B after removing i elements from the highest values
        int maxB = A[N - K - i];
        // Calculate the difference
        int diff = maxB - minB;
        // Update the minimum difference found
        minMaxMinDiff = min(minMaxMinDiff, diff);
    }

    cout << minMaxMinDiff << endl;

    return 0;
}