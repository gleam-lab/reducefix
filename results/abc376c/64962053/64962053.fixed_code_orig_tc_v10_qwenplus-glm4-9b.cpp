#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    
    // Read the sizes of the toys and the sizes of the boxes
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];
    
    // Sort the array A in descending order to get the largest toy size at the front
    sort(A.begin(), A.end(), greater<int>());
    
    // Sort the array B in ascending order to get the smallest box size that can fit the largest toy
    sort(B.begin(), B.end());
    
    // Find the largest box size that can fit the largest toy
    for (int i = 0; i < n; i++) {
        if (A[0] <= B[i]) {
            cout << B[i] << endl;
            return 0;
        }
    }
    
    // If no box can fit the largest toy, output -1
    cout << -1 << endl;
    return 0;
}