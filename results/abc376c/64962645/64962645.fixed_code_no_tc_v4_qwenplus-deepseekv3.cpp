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

    if (x != -1) {
        vector<int> merged_boxes = B;
        merged_boxes.push_back(x);
        sort(merged_boxes.begin(), merged_boxes.end(), greater<int>());
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (A[i] > merged_boxes[i]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            x = -1;
        }
    }

    cout << x << endl;
    return 0;
}