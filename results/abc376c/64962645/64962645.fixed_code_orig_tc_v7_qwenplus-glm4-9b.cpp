#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    
    // Reading the sizes of toys and boxes
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];
    
    // Sort the toy sizes and box sizes in descending order to find the minimum x
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    // Initialize the minimum box size that can fit all toys
    int min_box_size = 0;
    
    // Find the minimum box size that can fit all toys
    for (int i = 0; i < n; i++) {
        // The minimum box size that can fit A[i] must be at least as large as B[i]
        min_box_size = max(min_box_size, B[i]);
    }
    
    // Check if this minimum box size is enough for any toy
    for (int i = 0; i < n; i++) {
        if (A[i] > min_box_size) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << min_box_size << endl;
    return 0;
}