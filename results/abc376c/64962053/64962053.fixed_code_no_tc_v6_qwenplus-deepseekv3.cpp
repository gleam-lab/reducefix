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
    
    int mismatch = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > B[i]) {
            mismatch = i;
            break;
        }
    }
    if (mismatch == -1) {
        // The new box must accommodate A[n-1]
        cout << A[n-1] << endl;
    } else {
        // Check if A[n-1] can be placed in the new box and others in existing boxes
        if (A[n-1] > B[n-2]) {
            // Need to check if the mismatch is only one position
            bool possible = true;
            for (int i = mismatch; i < n - 1; ++i) {
                if (A[i] > B[i]) {
                    possible = false;
                    break;
                }
            }
            if (possible && A[n-1] <= B[n-2]) {
                possible = false;
            }
            if (possible) {
                cout << A[n-1] << endl;
            } else {
                // Check another scenario: the new box takes the largest A[i] not fitting B[i]
                bool second_try = true;
                int cnt = 0;
                for (int i = 0; i < n - 1; ++i) {
                    if (A[i+1] > B[i]) {
                        cnt++;
                        if (cnt > 1) {
                            second_try = false;
                            break;
                        }
                    }
                }
                if (second_try) {
                    int x = -1;
                    for (int i = 0; i < n - 1; ++i) {
                        if (A[i+1] > B[i]) {
                            x = A[i+1];
                            break;
                        }
                    }
                    cout << x << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        } else {
            // Check if only one toy is left unassigned to existing boxes
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (A[i] > B[i]) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                cout << A[mismatch] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}