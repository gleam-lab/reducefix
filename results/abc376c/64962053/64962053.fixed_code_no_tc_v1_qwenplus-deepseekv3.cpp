#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            if (A[i] > B[i]) {
                if (x == -1 || A[i] < x) {
                    x = A[i];
                }
            }
        } else {
            if (x == -1 || A[i] < x) {
                x = A[i];
            }
        }
    }
    
    bool possible = true;
    int new_box = x;
    vector<int> boxes = B;
    boxes.push_back(new_box);
    sort(boxes.begin(), boxes.end());
    
    for (int i = 0; i < n; i++) {
        if (A[i] > boxes[i]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << new_box << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}