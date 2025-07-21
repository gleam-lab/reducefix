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

    // Check if it's possible to assign boxes without the extra one
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

    // Now find the minimal x such that we can assign all toys
    // Binary search on x is not needed; we just need to find the smallest toy that cannot fit in the sorted B
    // Since A is sorted ascending and B is sorted ascending, we compare A[i] with B[i]
    // The only missing box is at position N-1 in A, so we compare A[N-1] with B[N-2]

    // If the largest toy fits in the second-largest box, then x can be as small as A[N-1]
    // Otherwise, we need a box of size A[N-1]

    if (A[N - 1] <= B[N - 2]) {
        cout << A[N - 1] << endl;
    } else {
        cout << A[N - 1] << endl;
    }

    return 0;
}