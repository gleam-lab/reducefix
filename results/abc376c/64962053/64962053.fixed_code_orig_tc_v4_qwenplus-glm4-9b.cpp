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
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int x = -1;
    for (int i = 0; i < n - 1; i++) {
        // Check if the current box size is smaller than the toy size
        if (B[i] < A[i]) {
            // If the next box is also smaller, we cannot cover the previous toy
            if (i + 1 < n - 1 && B[i + 1] < A[i]) {
                x = -1;
                break;
            }
            // Otherwise, the current box size is sufficient to store the previous toy
            x = B[i];
        }
    }
    
    if (x == -1 && A[n - 1] > B[n - 2]) {
        // If we reach the end and the largest toy is bigger than the largest box, we need a new box of size at least 
        // as large as the largest toy
        x = A[n - 1];
    }
    
    cout << x << endl;
    return 0;
}