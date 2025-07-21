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

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> A_sorted = A;
    vector<long long> B_sorted = B;

    int i = 0, j = 0;
    long long x = -1;

    // We need to match N-1 toys to N-1 boxes, leaving one toy for the new box.
    // The new box must be >= the remaining toy's size.
    // The approach is to find the largest toy that cannot be matched to any box.
    // Alternatively, if all toys can be matched except one, the new box must be >= that toy's size.

    // First, try to match as many toys as possible to boxes.
    // The optimal way is to match the smallest N-1 toys to the boxes, leaving the largest toy to the new box.
    // Or, if the largest N-1 toys cannot be matched to the boxes, then there's no solution.

    // So we need to check two scenarios:
    // 1. The largest N-1 toys can be matched to the N-1 boxes.
    //    Then, the smallest x is the size of the remaining toy (the smallest).
    // 2. Else, the largest toy that cannot be matched to any box must be placed in the new box.

    // Sort both A and B in ascending order.
    // For the first N-1 toys (A[0..N-2]), check if each A[i] <= B[i]. If yes, then the remaining toy is A[N-1], and x must be >= A[N-1].
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << A.back() << endl;
        return 0;
    }

    // If not, then we need to try to match the largest N-1 toys (A[1..N-1]) to the boxes (B[0..N-2]).
    possible = true;
    for (int i = 1; i < N; ++i) {
        if (A[i] > B[i - 1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << A[0] << endl;
        return 0;
    }

    // If both scenarios fail, there's no solution.
    cout << -1 << endl;
    return 0;
}