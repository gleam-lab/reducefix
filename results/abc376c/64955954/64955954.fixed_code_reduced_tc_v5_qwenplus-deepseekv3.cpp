#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int low = 1, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        vector<int> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());
        bool possible = true;
        int box_ptr = 0;
        for (int i = 0; i < n; ++i) {
            while (box_ptr < boxes.size() && boxes[box_ptr] < A[i]) {
                ++box_ptr;
            }
            if (box_ptr >= boxes.size()) {
                possible = false;
                break;
            }
            ++box_ptr;
        }
        if (possible) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}