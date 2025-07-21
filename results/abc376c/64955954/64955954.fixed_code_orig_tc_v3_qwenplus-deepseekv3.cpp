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
    int x = -1;
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            if (x == -1) {
                x = A[i];
                i++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if (i < n) {
        if (x == -1) {
            x = A.back();
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    if (x != -1) {
        // Check if x is smaller than any box in B (which is not possible as B is sorted and x >= A's elements)
        cout << x << endl;
    } else {
        // All toys fit in existing boxes, so the new box can be of size 1 (but we need to place one toy in it)
        // So the minimal x is the smallest toy size (since all toys are placed, but one must be in the new box)
        // So the minimal x is the smallest toy size (but we need to place one toy in the new box)
        // But all toys fit in existing boxes, so we can pick any box size >= the smallest toy.
        // The minimal x would be the smallest toy size.
        cout << A[0] << endl;
    }
    return 0;
}