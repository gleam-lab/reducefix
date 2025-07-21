#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int x = A[n - 1];  // Initialize x with the largest toy size
    bool possible = true;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = n - 2; j >= i; j--) {  // If box size is greater or equal to toy size
            if (B[j] >= A[i]) {
                x = max(x, B[j] + 1);  // We can use box B[j] + 1 as the new smallest box size
                found = true;
                break;
            }
        }
        if (!found) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}