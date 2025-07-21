#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int j = n - 2; // start from the second last element in B array due to 1-based indexing in the problem statement
    for (int i = 0; i < n; ++i) {
        while (j >= 0 && A[i] > B[j]) --j; // find a box that can contain the current toy
        if (j < 0) { // no box found that can contain the current toy
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << B[j+1] << endl; // j+1 because j was decremented one extra time for the last loop iteration
    return 0;
}