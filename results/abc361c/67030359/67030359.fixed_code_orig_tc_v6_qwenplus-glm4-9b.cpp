#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    vector<int> A;

    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    // We need to find two elements such that removing them minimizes the difference
    // between the maximum and minimum of the remaining elements.
    // The strategy is to remove K largest or K smallest elements to minimize the range.
    int minDiff = A[N - 1] - A[0];

    for (int i = 0; i < min(K, N - K); ++i) {
        // The worst case is when we have to remove K smallest or K largest elements.
        // This would be when the difference between the K-th largest and K-th smallest
        // elements is maximum.
        minDiff = min(minDiff, A[N - 1 - i] - A[K + i]);
    }

    cout << minDiff << endl;

    return 0;
}