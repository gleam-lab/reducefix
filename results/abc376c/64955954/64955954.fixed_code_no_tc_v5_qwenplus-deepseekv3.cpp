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

    int low = 1;
    int high = 1e9;
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        vector<int> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());

        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (A[i] > boxes[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}