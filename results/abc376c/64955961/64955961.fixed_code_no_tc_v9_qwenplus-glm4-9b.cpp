#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<long long> A(N), B(N - 1);

    // Read toy sizes
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Read box sizes
    for (long long i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort both arrays to facilitate the comparison
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // The minimum size of the box that needs to be bought is determined by the largest toy
    // that cannot fit in the largest available box.
    long long smallestBoxSize = *max_element(A.begin(), A.end());

    // We need to check if this box size can fit in any of the existing boxes.
    // If it can, then it is the smallest box we need to buy.
    bool canFit = false;
    for (long long b : B) {
        if (b >= smallestBoxSize) {
            canFit = true;
            break;
        }
    }

    // If the largest toy can be fitted in the existing boxes, the answer is the size of the largest toy.
    // Otherwise, we need to buy a new box of size equal to the largest toy.
    if (canFit) {
        cout << smallestBoxSize << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}