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

    // We need to find the minimum size of a box that can be purchased
    // such that all toys can be placed in it according to the rules.
    long long minBoxSize = 0;
    for (int i = 0; i < N; ++i) {
        // Find the rightmost box that can fit the toy of size A[i]
        // We will iterate from right to left to find the first box that can fit the toy.
        int j = N - 2;
        bool canFit = false;
        while (j >= 0) {
            if (A[i] <= B[j]) {
                canFit = true;
                break;
            }
            j--;
        }
        // If the toy can fit in any box, we can update the minBoxSize
        // to be the maximum of the current minBoxSize and A[i].
        // (We use max because we need a box that can fit both the current toy
        // and potentially any larger toy in the left side of the array.)
        if (canFit) {
            minBoxSize = max(minBoxSize, A[i]);
        }
    }

    // If minBoxSize is still 0, it means no box was found that can fit all toys.
    // Otherwise, we output minBoxSize as the result.
    if (minBoxSize > 0) {
        cout << minBoxSize << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}