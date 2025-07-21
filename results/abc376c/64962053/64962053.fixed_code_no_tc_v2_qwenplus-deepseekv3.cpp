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
    int unmatched = -1;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (unmatched == -1) {
                unmatched = A[i];
                ++i;
            } else {
                // More than one toy cannot be placed in existing boxes
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // After loop, check remaining toys
    if (i < n) {
        if (unmatched == -1) {
            // Only one toy left
            unmatched = A[i];
        } else {
            // More than one toy left
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (unmatched == -1) {
        // All toys matched, need smallest possible x (but need to buy at least one box)
        // However, since all toys are matched, the new box can be any size >= the last toy's size.
        // But problem says to store all toys in boxes, and boxes must be separate. So, need to ensure that the new box is used.
        // So, the minimal x is max(A.back(), min(B.back(), ...))? Or perhaps it's better to say that the new box must be used.
        // However, all toys are matched to existing boxes, so no new box is needed, which contradicts the problem statement requiring a new box purchase.
        // This suggests that the initial approach might miss something.
        // The problem says he must purchase one box of size x, even if existing boxes can hold all toys.
        // So, the minimal x is the smallest not interfering with existing assignments.
        // Thus, minimal x is 1 (since no toy is left, but the problem requires purchasing a box; but perhaps x can be 1 if no toy is placed in it).
        // But the problem says he wants to place all toys in boxes, so this scenario might not be possible.
        // Hence, perhaps if all toys are matched, it's impossible, but the initial problem statement says he must purchase a box. So, this case is impossible.
        cout << -1 << endl;
    } else {
        cout << unmatched << endl;
    }
    
    return 0;
}