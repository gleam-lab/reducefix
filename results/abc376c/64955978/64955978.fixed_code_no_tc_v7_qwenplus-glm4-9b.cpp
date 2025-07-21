#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort A and B in descending order
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    // Check if the largest toy can fit into any of the given boxes
    bool found = false;
    for (int i = 0; i < N - 1; ++i) {
        if (A[0] <= B[i]) {
            found = true;
            break;
        }
    }

    if (!found) {
        // If the largest toy cannot fit into any of the given boxes,
        // we need to find the smallest box size that can fit the largest toy
        long long min_box_size = A[0];
        for (long long size : B) {
            if (size < min_box_size) {
                break;
            }
            min_box_size = size;
        }
        cout << min_box_size << endl;
    } else {
        // If the largest toy can fit into some box, we need to check if all toys can be placed
        bool all_placed = true;
        for (int i = 0; i < N; ++i) {
            bool placed = false;
            for (int j = 0; j < N - 1; ++j) {
                if (A[i] <= B[j]) {
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                all_placed = false;
                break;
            }
        }
        if (all_placed) {
            cout << B[0] << endl; // The size of the largest existing box
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}