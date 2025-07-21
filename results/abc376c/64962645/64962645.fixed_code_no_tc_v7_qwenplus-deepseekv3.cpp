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
    
    int i = 0, j = 0;
    int required_x = -1;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            required_x = A[i];
            i++;
        }
    }
    
    if (required_x == -1) {
        if (i < n) {
            required_x = A.back();
        } else {
            required_x = 1; // All toys fit in existing boxes, so x can be any size >= smallest toy
        }
    }
    
    if (required_x != -1) {
        // Verify if all toys can be placed with the new box of size required_x
        vector<int> boxes = B;
        boxes.push_back(required_x);
        sort(boxes.begin(), boxes.end());
        
        i = 0; j = 0;
        bool possible = true;
        while (i < n && j < n) {
            if (A[i] <= boxes[j]) {
                i++;
                j++;
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << required_x << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}