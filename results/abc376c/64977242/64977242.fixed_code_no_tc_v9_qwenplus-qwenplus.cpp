#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys and boxes in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit the smallest N-1 toys into the smallest N-1 boxes
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // The required size of the additional box is at least A[N-1]
    // Also, it must be larger than B[i] - sum of smaller toys? No.
    // We need to find minimal x such that A[N-1] <= x and x does not interfere with previous allocations.

    // Since the smallest N-1 toys are already placed,
    // the only toy left is A[N-1], which needs a box >= its size.
    // So, the minimum x is max(A[N-1], ... )

    // But we also have to ensure that adding this box allows us to place all toys.
    // Because B is sorted and A is sorted,
    // the biggest toy must go to the biggest remaining available box.

    // Find the minimum x such that when added to B and sorted, the full matching works.

    // To compute minimal required x:
    // For each i in [0, N-1), we have used B[i] to accommodate A[i].
    // Only one toy A[N-1] remains unplaced.
    // We need to find which box among B[i] can be swapped out to accommodate A[N-1],
    // while the swapped-out toy can be moved to the new box of size x.

    // Try all candidates: for each i from 0 to N-2:
    // If we use B[i] to store some smaller toy (say A[j] where j < N-1),
    // and instead use x to store A[N-1], then x must be <= B[i] and >= A[N-1].

    // The best candidate is the smallest B[i] that is >= A[N-1]

    long long largest_toy = A.back();
    long long min_box_size = -1;

    for (int i = 0; i < N - 1; ++i) {
        if (B[i] >= largest_toy) {
            if (min_box_size == -1 || B[i] < min_box_size) {
                min_box_size = B[i];
            }
        }
    }

    if (min_box_size != -1) {
        // We can replace one existing box with this one and put the replaced toy in the new box
        cout << largest_toy << endl;
    } else {
        // None of the existing boxes can hold the largest toy
        cout << -1 << endl;
    }

    return 0;
}