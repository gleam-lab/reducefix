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

    // Sort toys and boxes in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit the smallest N-1 toys into the N-1 boxes
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

    // The required size of the extra box is the maximum toy that doesn't fit in the largest box
    long long minRequiredBox = A.back();

    // If the largest toy fits in the largest box, then x can be zero (no need to buy)
    if (A.back() <= B.back()) {
        cout << 0 << endl;
    } else {
        cout << minRequiredBox << endl;
    }

    return 0;
}