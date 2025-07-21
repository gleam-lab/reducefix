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

    // Sort toys and available boxes in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit all but one toy into the existing boxes
    // The largest toy will go into the purchased box
    int j = 0; // pointer for B
    for (int i = 0; i < N; ++i) {
        if (j < N - 1 && A[i] <= B[j]) {
            ++j;
        }
    }

    if (j == N - 1) {
        // All but one toy can be placed in current boxes
        // The smallest unplaced toy needs to go to the new box
        cout << A[N - 1] << endl;
    } else {
        // Not enough capacity even with the extra box
        cout << -1 << endl;
    }

    return 0;
}