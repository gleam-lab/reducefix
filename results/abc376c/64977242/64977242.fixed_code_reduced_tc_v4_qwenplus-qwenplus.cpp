#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<long long> B(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort toys and boxes in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can fit N-1 smallest toys into existing boxes
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

    // The minimum size of the additional box needed
    long long min_box_size = 0;

    // Find the first toy that doesn't fit in the corresponding box
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] > B[i]) {
            min_box_size = A[i + 1];
            break;
        }
    }

    // Edge case: all toys fit in the sorted boxes, then we can use the smallest toy as the extra box
    if (min_box_size == 0) {
        min_box_size = A[0];
    }

    cout << min_box_size << endl;
    return 0;
}