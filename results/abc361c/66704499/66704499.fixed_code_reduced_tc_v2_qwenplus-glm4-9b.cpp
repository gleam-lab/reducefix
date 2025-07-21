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

    sort(A.begin(), A.end());

    // Initial range before any removals
    int minA = A[0], maxA = A[N - 1];
    int initial_range = maxA - minA;

    int best_range = initial_range;
    int left = 0, right = N - 1;

    // Use a sliding window to find the smallest range
    while (right - left + 1 > K) {
        if (A[right] - A[left] > best_range) {
            // Remove one element from the larger side to reduce the range
            if (A[right] - A[left - 1] < best_range) {
                right--;
            } else {
                left++;
            }
        } else {
            // If the current range is better, store it
            best_range = A[right] - A[left];
        }
    }

    cout << best_range << endl;

    return 0;
}