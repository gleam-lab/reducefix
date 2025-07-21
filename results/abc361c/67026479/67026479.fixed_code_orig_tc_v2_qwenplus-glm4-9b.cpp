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

    // Create a prefix and a suffix array
    vector<int> prefix_min(N), prefix_max(N), suffix_min(N), suffix_max(N);

    prefix_min[0] = A[0];
    prefix_max[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], A[i]);
        prefix_max[i] = max(prefix_max[i - 1], A[i]);
    }

    suffix_min[N - 1] = A[N - 1];
    suffix_max[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        suffix_min[i] = min(suffix_min[i + 1], A[i]);
        suffix_max[i] = max(suffix_max[i + 1], A[i]);
    }

    int answer = INT_MAX;

    // Consider all possible subarrays of length K
    for (int left = 0; left < N - K; ++left) {
        int right = left + K - 1;
        int right_limit = left + K;
        // Ensure there is enough space to remove K elements after removing the subarray
        if (right_limit <= N - 1) {
            // Minimum of the sequence after removing the subarray
            int min_after = min(A[left], suffix_min[right + 1]);
            // Maximum of the sequence after removing the subarray
            int max_after = max(A[right], prefix_max[left - 1]);
            // Update the answer
            answer = min(answer, max_after - min_after);
        }
    }

    cout << answer << endl;
}