#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Prepare a vector of all box sizes including the toys' sizes
    vector<int> box_sizes(N);
    for (int i = 0; i < N; ++i) {
        box_sizes[i] = A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        box_sizes[i + 1] = max(B[i], A[i]);
    }
    sort(box_sizes.rbegin(), box_sizes.rend());

    // Find the smallest size where the number of boxes of that size is at least the number of toys
    for (int i = 0; i < N; ++i) {
        if (box_sizes[i] >= A[i]) {
            // We need to check if all toys can be placed in boxes of this size and larger
            bool possible = true;
            for (int j = 0; j < N; ++j) {
                if (box_sizes[i] > A[j]) {
                    break;
                }
                if (box_sizes[i] < B[j] || box_sizes[i] < A[j]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                cout << box_sizes[i] << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}