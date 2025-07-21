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

    // Sort the array to easily find the smallest and largest elements
    sort(A.begin(), A.end());

    // If K is zero, we cannot remove any elements, so the result is zero
    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }

    // If K is odd, we need to consider the scenario where we remove the middle element to potentially get a larger difference
    // If K is even, we can directly consider removing two middle elements
    if (K % 2 == 1) {
        // Case 1: Remove the middle element
        int case1 = A[N - K / 2] - A[K / 2 + 1];
        // Case 2: Remove the element to the right of the middle element
        int case2 = A[N - 1 - K / 2] - A[K / 2];
        // Case 3: Remove the element to the left of the middle element
        int case3 = A[N - 2 - K / 2] - A[K / 2];
        // We want the maximum difference possible
        cout << max({case1, case2, case3}) << endl;
    } else {
        // Case 1: Remove two middle elements from the left side
        int case1 = A[N - K / 2 - 1] - A[K / 2];
        // Case 2: Remove two middle elements from the right side
        int case2 = A[N - 1 - K / 2] - A[K / 2 + 1];
        // We want the maximum difference possible
        cout << max(case1, case2) << endl;
    }

    return 0;
}