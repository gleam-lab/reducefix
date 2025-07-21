#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Sort the array to easily find the minimum and maximum values after removing K elements
    sort(A.begin(), A.end());

    // Initialize pointers to the ends of the array
    int left = N - K - 1;
    int right = N - 1;

    // We need to find the minimum possible maximum value and the maximum possible minimum value
    // after removing K elements. To do this, we can remove the largest or smallest
    // (K-1) elements from the ends of the array, and then calculate the difference
    // between these two values.

    // Calculate the maximum possible minimum value by possibly removing the smallest
    // (K-1) elements
    int minMax = A[left]; // This is the maximum value of the remaining sequence after removing K elements

    // Calculate the minimum possible maximum value by possibly removing the largest
    // (K-1) elements
    int maxMin = A[right - K + 1]; // This is the minimum value of the original array

    // The answer is the difference between minMax and maxMin
    cout << minMax - maxMin << endl;

    return 0;
}