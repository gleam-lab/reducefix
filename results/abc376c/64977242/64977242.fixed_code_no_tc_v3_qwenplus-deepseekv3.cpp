#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if the first N-1 toys can fit into the N-1 boxes
    bool possible = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // The new box must accommodate the largest toy not covered by the existing boxes
    long long x = A.back(); // The largest toy

    // Alternatively, if the largest toy is already covered by the largest box,
    // then the new box might need to cover the second largest toy not covered, etc.
    // But since we've sorted and checked the first N-1 toys fit, the largest toy is the one left.

    cout << x << endl;
    return 0;
}