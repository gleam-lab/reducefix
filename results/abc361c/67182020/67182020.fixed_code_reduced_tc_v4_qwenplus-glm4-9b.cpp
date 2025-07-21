#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int minDiff = INT_MAX;

    // Iterate through all possible pairs of smallest and largest elements to remove
    for (int i = 0; i <= min(K/2, N - K - 1); i++) {
        int leftToRemove = A[i];               // Smallest element to remove
        int rightToRemove = A[N - K - 1 - (i * 2)]; // Largest element to remove

        // Calculate the range of B
        int B_min = A[0]; // The minimum element of B
        int B_max = A[N - 1]; // The maximum element of B

        // Update the minimum difference found so far
        minDiff = min(minDiff, B_max - B_min);
    }

    cout << minDiff << endl;
    return 0;
}