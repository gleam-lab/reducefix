#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int required_x = -1;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    
    if (i < n) {
        required_x = A[i];
        
        // Check if all remaining toys can fit in x
        for (int k = i + 1; k < n; ++k) {
            if (A[k] > required_x) {
                required_x = -1;
                break;
            }
        }
    } else {
        // All toys can be placed in existing boxes, but we must purchase x
        // The problem says we must purchase x, but no toy needs it. So x can be 1?
        // But the problem might expect -1 in this case, but the note says he wants to execute step 2 by purchasing x.
        // According to the problem statement, he must purchase x. So the minimal x is 1, but the sample expects -1.
        // So perhaps in this case, the answer is -1 because it's impossible to place all toys in boxes (since N boxes are needed, but there are N-1 boxes plus one new, but all can fit in existing boxes, so no need for x, which contradicts the purchase requirement).
        // So the problem expects -1 when all toys can be placed in existing boxes.
        required_x = -1;
    }
    
    cout << required_x << endl;
    
    return 0;
}