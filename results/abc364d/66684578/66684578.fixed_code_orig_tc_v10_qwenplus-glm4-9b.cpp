#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    for (int q = 0; q < Q; ++q) {
        long long B, k;
        std::cin >> B >> k;

        // Binary search for k-th closest distance
        long long left = 0, right = 10LL * 1e8 + 1; // We use 10e8 because coordinates can be as large as 10^8
        while (right - left > 1) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            for (int i = 0; i < N; ++i) {
                long long dist = std::abs(A[i] - B);
                if (dist <= mid) {
                    ++count;
                }
            }

            if (count >= k) {
                left = mid; // Need a smaller distance
            } else {
                right = mid; // Need a larger distance
            }
        }

        std::cout << left << std::endl; // Output the k-th closest distance
    }

    return 0;
}