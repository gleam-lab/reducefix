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

    // Sort the array to make it easier to find minimums and maximums
    sort(A.begin(), A.end());

    // To find the minimum possible value of max(B) - min(B), we can remove up to K elements
    // in such a way that we maximize the difference between the maximum and minimum values
    // that remain. This happens when we remove the smallest and largest K/2 elements.
    // For the remaining elements, we need to check the value of the element right before
    // the smallest K/2 elements and the last element after the largest K/2 elements.

    int minDiff = A[N-1-K/2] - A[K/2]; // Removing K/2 smallest and K/2 largest
    if (A[N-2-K/2] - A[K/2+1] > minDiff) {
        minDiff = A[N-2-K/2] - A[K/2+1]; // Removing (K/2-1) smallest and (K/2+1) largest
    }
    if (A[N-K/2-1] - A[K/2] > minDiff) {
        minDiff = A[N-K/2-1] - A[K/2]; // Removing K/2 largest and K/2 smallest
    }

    cout << minDiff << endl;
    return 0;
}