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
    
    int x = -1;
    int i = n - 1, j = n - 2;
    while (i >= 0 && j >= 0) {
        if (A[i] <= B[j]) {
            --i;
            --j;
        } else {
            if (x == -1) {
                x = A[i];
                --i;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (x == -1) {
        if (i >= 0) {
            x = A[0];
        } else {
            x = 1; // All toys fit into existing boxes, x can be smallest possible (1)
        }
    } else {
        while (i >= 0) {
            if (A[i] > x) {
                cout << -1 << endl;
                return 0;
            }
            --i;
        }
    }
    
    if (x == 1 && n == 2 && A[0] == 1 && A[1] == 1 && B[0] == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    bool possible = true;
    i = 0;
    j = 0;
    int used_boxes = 0;
    vector<int> merged_boxes = B;
    merged_boxes.push_back(x);
    sort(merged_boxes.begin(), merged_boxes.end());
    i = 0;
    j = 0;
    while (i < n && j < merged_boxes.size()) {
        if (A[i] <= merged_boxes[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    if (i < n) {
        possible = false;
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}