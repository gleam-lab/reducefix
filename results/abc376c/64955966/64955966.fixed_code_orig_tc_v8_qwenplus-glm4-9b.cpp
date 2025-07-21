#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort the toys and boxes in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    // Initialize the minimum box size x as the size of the last box
    int x = B[N - 2];

    // Determine if there exists a smaller box size x that can still fit all toys
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > x) {
            x = A[i];
        }
    }

    if (x < A[N - 1]) {
        x = A[N - 1]; // If the last toy can't fit in any of the smaller boxes, x must be at least the size of the last toy
    }

    cout << x << endl;

    return 0;
}