#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }

    // Sort toy sizes and box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Start with the smallest possible box size that could fit the largest toy
    int min_box_size = A.back();

    // Check if there exists a box that can fit the largest toy
    bool can_fit = false;
    for (int i = 0; i < n - 1; i++) {
        if (B[i] >= min_box_size) {
            can_fit = true;
            break;
        }
    }

    // If no box can fit the largest toy, we need to increase the box size
    if (!can_fit) {
        cout << min_box_size << endl;
        return 0;
    }

    // If we have enough boxes that can fit the largest toy, we need to check if we can fit the second largest toy
    // and so on until we find the smallest box size that can fit the smallest toy.
    int i = n - 1; // index of the current toy we are trying to fit
    while (i > 0 && B[i - 1] >= A[i]) {
        i--;
    }

    // minimum_size is the size of the box that can fit the i-th smallest toy
    int min_size = A[i] + (i < n - 1 ? 1 : 0);
    cout << min_size << endl;
}