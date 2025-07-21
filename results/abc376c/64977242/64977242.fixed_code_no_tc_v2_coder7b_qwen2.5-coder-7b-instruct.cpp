#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> A, B;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Sort both arrays in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    // Find the maximum value of B that is less than or equal to the corresponding A
    long long minBoxSize = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] <= B[i]) {
            minBoxSize = max(minBoxSize, B[i]);
        } else {
            // If we cannot place the ith toy in any of the existing boxes,
            // then we need a new box of at least size A[i]
            minBoxSize = max(minBoxSize, A[i]);
            break;
        }
    }

    // Check if we were able to place all toys without needing a new box
    if (minBoxSize == 0 && !all_of(B.begin(), B.end(), [&](long long b){return b >= A.back();})) {
        minBoxSize = A.back();
    }

    cout << (minBoxSize ? minBoxSize : -1) << endl;

    return 0;
}