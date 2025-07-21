#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (long long &a : A) cin >> a;
    for (long long &b : B) cin >> b;

    // Sort the toy sizes in descending order
    sort(A.rbegin(), A.rend());

    // Sort the box sizes in ascending order
    sort(B.begin(), B.end());

    // The minimum box size needed to fit the largest toy if none of the existing boxes fit
    long long minBoxSize = A[0];

    // Variable to check if all toys can fit in the existing boxes
    bool canFit = true;

    // Check if all toys can fit in the existing boxes
    for (long long i = 0; i < N - 1; ++i) {
        if (A[i] < B[i]) {
            canFit = false;
            break;
        }
    }

    // If all toys can fit, the minimum box size needed is the size of the largest toy
    if (canFit) {
        cout << A[0] << endl;
    } else {
        // If not, we need to find the smallest box size that can fit the largest toy
        long longLo = 1, hi = minBoxSize;
        long long smallestBoxSize = -1;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            // Check if there is a box of size 'mid' or larger that can fit the largest toy
            bool canUseSizeMid = false;
            for (long long i = 0; i < N - 1; ++i) {
                if (B[i] >= mid) {
                    canUseSizeMid = true;
                    break;
                }
            }
            // If we can use a box of size 'mid', then try for a smaller size
            if (canUseSizeMid) {
                hi = mid - 1;
                smallestBoxSize = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << smallestBoxSize << endl;
    }

    return 0;
}