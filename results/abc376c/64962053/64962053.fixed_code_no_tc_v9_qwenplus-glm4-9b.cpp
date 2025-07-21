#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    // Sort the sizes of boxes and toys in non-decreasing order
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    
    // If the largest toy is smaller than the smallest box, no solution exists
    if (A[0] > B[0]) {
        cout << -1 << endl;
        return 0;
    }
    
    // Check the feasibility of each box starting from the smallest
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] <= B[i]) {
            // If the current box can fit the current toy, check the next one
            if (i == n - 2 || A[i + 1] <= B[i + 1]) {
                // We can place all toys in the existing boxes or the last box
                // The minimum box size x is the size of the smallest box that can fit the largest toy
                cout << A[n - 1] << endl;
                return 0;
            }
        } else {
            // If the current box cannot fit the current toy, we need to buy a new box
            cout << A[i] << endl;
            return 0;
        }
    }
    
    // If we could place all toys without needing to buy a new box, the minimum x is the size of the largest toy
    cout << A[0] << endl;
    return 0;
}