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

    // Sort the array to make it easier to find the min and max values after removal of K elements
    sort(A.begin(), A.end());

    // After removing K elements, we need to determine the smallest possible range of elements in A
    // that can form the new sequence B. To do this, we can consider removing elements from both ends
    // of the sorted array, as removing the largest or smallest elements will reduce the range.

    // The initial range of values in A is from A[0] to A[N-1]
    int minVal = A[0], maxVal = A[N-1];
    int left = 0, right = N - 1;

    // We try to remove K elements from both ends of the array
    for (int i = 0; i < K; ++i) {
        // Remove an element from the left
        if (left + 1 <= right) { // Ensure that there is at least one element left on the right to form a valid range
            minVal = min(minVal, A[left + 1]);
        }
        left++; // Remove the element at the left end

        // Remove an element from the right
        if (right - 1 >= left) { // Ensure that there is at least one element left on the left to form a valid range
            maxVal = max(maxVal, A[right - 1]);
        }
        right--; // Remove the element at the right end
    }

    // The minimum possible value of the maximum value of B minus the minimum value of B
    // is the difference between maxVal and minVal after removing K elements
    cout << maxVal - minVal << endl;

    return 0;
}