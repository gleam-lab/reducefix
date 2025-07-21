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
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int box_ptr = 0;
    int x = -1;
    
    for (int i = 0; i < n; ++i) {
        if (box_ptr < n - 1 && B[box_ptr] >= A[i]) {
            box_ptr++;
        } else {
            if (x == -1) {
                x = A[i];
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << x << endl;
    return 0;
}