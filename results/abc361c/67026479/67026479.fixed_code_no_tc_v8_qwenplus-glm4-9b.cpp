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

    // Sort the array to easily find the minimum and maximum of different sizes
    sort(A.begin(), A.end());

    // The minimum possible value of the maximum of B minus the minimum of B
    // will be the difference between the max and min of the two largest remaining subarrays
    // after removing K elements.
    long long minDiff = LLONG_MAX;

    // We need to consider removing K elements in the worst case to create the largest possible difference
    // The two largest remaining subarrays after removing K elements will be:
    // 1. The subarray from index 0 to N-K-1
    // 2. The subarray from index K to N-1
    // We calculate the difference between the max and min of these two subarrays
    int max1 = A[N-K-1];
    int min1 = A[0];
    int max2 = A[N-1];
    int min2 = A[K]; // This is A[1] because K is 1-based for the second subarray

    minDiff = min(minDiff, max(max1 - min1, max2 - min2));

    cout << minDiff << endl;

    return 0;
}