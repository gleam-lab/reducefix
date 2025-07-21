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
    for (int i = 0; i < n; ++i) {
        int j = i;
        if (j < n - 1) {
            if (A[i] > B[j]) {
                if (x == -1) {
                    x = A[i];
                } else {
                    x = max(x, A[i]);
                }
            }
        } else {
            if (x == -1) {
                x = A[i];
            } else {
                x = max(x, A[i]);
            }
        }
    }

    // Now, verify if with x, all toys can be placed
    vector<int> boxes = B;
    if (x != -1) {
        boxes.push_back(x);
        sort(boxes.begin(), boxes.end());
    }

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