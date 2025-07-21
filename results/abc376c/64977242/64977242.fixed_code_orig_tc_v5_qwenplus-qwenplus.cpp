#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's possible to place N-1 smallest toys into the N-1 boxes
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

    // The minimum size of the extra box needed is the max of:
    // A[i] - B[i] where A[i] > B[i]
    // We only need one such case to determine x
    long long min_x = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            min_x = max(min_x, A[i]);
        }
    }

    // Edge case: all boxes can fit the corresponding toy
    // So we need a box that fits the last remaining toy
    if (min_x == 0) {
        min_x = A.back();
    } else {
        // Compare with the largest toy not yet placed in any box
        min_x = max(min_x, A.back());
    }

    cout << min_x << endl;
    return 0;
}