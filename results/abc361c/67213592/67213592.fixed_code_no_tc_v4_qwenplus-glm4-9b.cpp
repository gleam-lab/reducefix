#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort the array to facilitate easy access to the min and max of remaining elements
    sort(A.begin(), A.end());

    // We need to find the minimum possible max of B minus the minimum of B
    // We can achieve this by removing at most k elements that can influence the max and min values of B
    // We consider two cases because removing elements from the beginning or the end of the array
    // can potentially reduce the range (max - min) more effectively.

    // Case 1: Remove elements from the beginning and end
    int minRange1 = A[n - 1] - A[k]; // Remove k elements from the end
    int maxRange1 = A[n - k - 1] - A[0]; // Remove k elements from the start

    // Case 2: Remove elements from the end only
    int minRange2 = A[n - 1] - A[k - 1]; // Remove k-1 elements from the end and 1 element from the start
    int maxRange2 = A[n - 2] - A[0]; // Remove k-2 elements from the end and 2 elements from the start

    // Choose the minimum range from the two cases
    int result = min({minRange1, maxRange1, minRange2, maxRange2});

    cout << result << endl;
    return 0;
}