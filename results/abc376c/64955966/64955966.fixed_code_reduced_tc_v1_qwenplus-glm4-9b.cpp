#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    // Calculate the maximum sizes that are possible to store the toys
    int max_a = *max_element(A.begin(), A.end());
    int max_b = *max_element(B.begin(), B.end());
    int max_box_size = ceil(max_a / max_b) * max_b;

    // Initialize the smallest box size to a large value
    int min_x = INT_MAX;

    // Check if there is a box size that can store all toys
    for (int i = 0; i < N; i++) {
        int required_box_size = ceil(A[i] / max_b) * max_b;
        if (required_box_size <= max_box_size) {
            min_x = min(min_x, required_box_size);
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    // If all toys can be stored in some box size, print the minimum size
    cout << min_x << endl;

    return 0;
}