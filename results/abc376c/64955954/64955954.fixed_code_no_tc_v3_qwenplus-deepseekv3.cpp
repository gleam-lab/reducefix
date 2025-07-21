#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Binary search for the minimal x
    int left = 1, right = 1e9;
    int answer = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        vector<int> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());
        
        bool possible = true;
        int i = 0, j = 0;
        for (; i < n && j < n; ++j) {
            if (boxes[j] >= A[i]) {
                ++i;
            }
        }
        if (i >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}