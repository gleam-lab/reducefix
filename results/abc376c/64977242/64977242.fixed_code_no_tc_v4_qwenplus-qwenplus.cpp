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

    // The required size of the additional box is at least A[N-1]
    // But also, we need to ensure it's larger than what's already covered
    long long min_required = A.back();

    // Find the maximum toy that must go into the new box.
    // If there are toys smaller than or equal to available boxes, they can use them,
    // so we find the first toy (from largest to smallest) which must go into the new box.

    // Create reverse sorted lists to match largest toys with largest available boxes
    vector<long long> A_sorted_desc = A;
    vector<long long> B_sorted_desc = B;
    sort(A_sorted_desc.begin(), A_sorted_desc.end(), greater<long long>());
    sort(B_sorted_desc.begin(), B_sorted_desc.end(), greater<long long>());

    for (int i = 0; i < N - 1; ++i) {
        if (A_sorted_desc[i] > B_sorted_desc[i]) {
            min_required = max(min_required, A_sorted_desc[i]);
            break;
        }
    }

    cout << min_required << endl;
    return 0;
}