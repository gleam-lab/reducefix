#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > B[i]) {
            x = max(x, A[i]);
        }
        if (i > 0 && A[i] > B[i - 1]) {
            x = max(x, B[i - 1]);
        }
    }
    
    if (x == 0) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
    
    return 0;
}