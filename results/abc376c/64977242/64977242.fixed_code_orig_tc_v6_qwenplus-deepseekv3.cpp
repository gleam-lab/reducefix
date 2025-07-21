#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;
    // Check if we can place all toys without the new box
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        // All toys can be placed in N-1 boxes; x can be any size >=1, so min is 1
        cout << 1 << endl;
        return 0;
    }

    // Now find the minimal x by checking the largest N toys
    // We need to place N toys in N boxes (N-1 existing + new one)
    // The approach is to sort both A and B, then find the minimal x such that:
    // The largest toy not covered by the boxes is <= x, and the rest can be matched
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // The minimal x is the maximum between:
    // 1. The largest A[i] that is not covered by B[i] (considering B is extended with x)
    // So we need to find the minimal x such that when B is extended with x and sorted, each A[i] <= B'[i],
    // where B' is B sorted ascendingly with x added.

    // Possible x must be >= A[N-1] if B[N-2] < A[N-1], else x can be 1
    // So the minimal x is the maximum A[i] that is not covered by B[i], considering the new box.

    // The strategy is:
    // 1. Sort A and B in ascending order.
    // 2. For each i from 0 to N-1, if A[i] > B[i] (with B extended with x at some position), then x must be >= A[i].
    // Specifically, the minimal x is the maximum A[i] where B[i] (in the extended B') is the new box.

    // To find this, we can:
    // - Iterate through the sorted A and B, and for each position where the corresponding box in B is smaller than A[i],
    //   note that A[i] would require the new box. The minimal x is the maximum such A[i].

    // However, since we can choose any x, the optimal x is the largest A[i] that cannot be placed in B[i], when considering the new box.

    // So the approach is:
    // - Sort both arrays.
    // - Check if the first N-1 toys can be placed in the first N-1 boxes (A[i] <= B[i] for i < N-1)
    //   and the Nth toy is placed in the new box. Then x must be >= A[N-1].
    // - If not, then the minimal x is the maximum A[i] that is not covered by B[i] (with the new box handling the largest such A[i]).

    // So the minimal x is the maximum between:
    // - A[N-1] (if not covered by any B)
    // - Or the largest A[i] where A[i] > B[i] (with B sorted in ascending order)

    // So the algorithm is:
    // 1. Sort A and B in ascending order.
    // 2. For each i from 0 to N-2:
    //    if A[i] > B[i], then x must be >= A[i], but since we can only have one new box, we must choose the maximum such A[i].
    // 3. Additionally, the Nth toy (A[N-1]) must be placed in the new box if B[N-2] < A[N-1].

    // So the minimal x is the maximum of:
    // - A[N-1] (since it must be placed in the new box if B[N-2] < A[N-1])
    // - The maximum A[i] for i < N-1 where A[i] > B[i] (if any)

    long long x = -1;
    bool can_store = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            can_store = false;
            break;
        }
    }
    if (can_store) {
        x = 1;
    } else {
        vector<long long> A_sorted = A;
        vector<long long> B_sorted = B;
        sort(A_sorted.begin(), A_sorted.end());
        sort(B_sorted.begin(), B_sorted.end());
        
        long long max_uncovered = 0;
        bool found = false;
        for (int i = 0; i < N; ++i) {
            if (i < N - 1) {
                if (A_sorted[i] > B_sorted[i]) {
                    if (A_sorted[i] > max_uncovered) {
                        max_uncovered = A_sorted[i];
                        found = true;
                    }
                }
            } else {
                if (A_sorted[i] > max_uncovered) {
                    max_uncovered = A_sorted[i];
                    found = true;
                }
            }
        }
        if (found) {
            x = max_uncovered;
        } else {
            x = 1;
        }
    }

    cout << x << endl;

    return 0;
}