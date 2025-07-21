#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
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
    
    bool possible = true;
    int new_box_count = 1;
    int a_ptr = 0, b_ptr = 0;
    
    while (a_ptr < n && b_ptr < n - 1) {
        if (A[a_ptr] <= B[b_ptr]) {
            a_ptr++;
            b_ptr++;
        } else {
            if (new_box_count > 0 && A[a_ptr] <= x) {
                a_ptr++;
                new_box_count--;
            } else {
                possible = false;
                break;
            }
        }
    }
    
    if (a_ptr < n) {
        if (new_box_count > 0 && A[a_ptr] <= x) {
            a_ptr++;
            new_box_count--;
        } else {
            possible = false;
        }
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}