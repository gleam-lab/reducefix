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
    
    int x = -1;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            if (A[i] > B[i]) {
                x = A[i];
                break;
            }
        } else {
            x = A[i];
        }
    }
    
    if (x == -1) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> boxes = B;
    boxes.push_back(x);
    sort(boxes.begin(), boxes.end(), greater<int>());
    sort(A.begin(), A.end(), greater<int>());
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (A[i] > boxes[i]) {
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