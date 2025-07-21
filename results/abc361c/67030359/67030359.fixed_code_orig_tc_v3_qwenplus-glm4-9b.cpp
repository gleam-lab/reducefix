#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Initial answer is the difference between the maximum and minimum elements
    int max_diff = A[N - 1] - A[0];

    // Iterate from both ends towards the center
    for (int i = 0, j = N - 1; i < j; ++i, --j) {
        // Calculate the number of elements to remove from each end
        int rem_left = std::min(i, K);
        int rem_right = std::min(j, K);

        // If the number of elements to remove from both ends is less than or equal to K, calculate the potential new answer
        if (rem_left + rem_right <= K) {
            int new_diff = std::max(A[j - rem_right] - A[i + rem_left], A[j] - A[i]);
            max_diff = std::max(max_diff, new_diff);
        }
    }

    std::cout << max_diff << std::endl;

    return 0;
}