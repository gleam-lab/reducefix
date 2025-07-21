#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to assign N toys to N boxes: N-1 real boxes + 1 custom box
    // Each toy must go into a box >= its size, and each box can hold at most one toy

    // Try greedy matching:
    // For each toy (sorted ascending), try to match with smallest possible box
    // If any toy cannot be matched with available boxes, use custom box for it

    // We will keep track of which boxes are used
    vector<bool> used(n - 1, false);

    // Two pointers approach
    int j = 0; // pointer for boxes
    for (int i = 0; i < n && j < n - 1; ++i) {
        if (A[i] <= B[j]) {
            ++j; // use this box for current toy
        }
        // else: box is too small, we need to save this toy for custom box
    }

    // The number of unmatched toys is (n - j)
    // We need to choose the minimal x such that we can fit all unmatched toys in 1 box
    // So x needs to be at least max(A[j], A[j+1], ..., A[n-1])

    if (j < n) {
        long long min_x = *max_element(A.begin() + j, A.end());
        cout << min_x << endl;
    } else {
        // All toys can be placed in existing boxes (should not happen since boxes = n-1)
        // But just in case...
        cout << -1 << endl;
    }

    return 0;
}