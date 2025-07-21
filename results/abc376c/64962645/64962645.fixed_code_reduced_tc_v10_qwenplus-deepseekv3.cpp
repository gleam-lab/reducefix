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
    
    int k = 0;
    for (int i = 0, j = 0; i < n && j < n - 1; ) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            ++k;
            ++i;
        }
    }
    
    if (k > 1) {
        cout << -1 << endl;
    } else {
        int x = (k == 1) ? A[0] : A[n - 1];
        bool possible = true;
        int new_box = x;
        vector<int> boxes = B;
        boxes.push_back(new_box);
        sort(boxes.begin(), boxes.end(), greater<int>());
        
        for (int i = 0, j = 0; i < n && j < n; ) {
            if (A[i] <= boxes[j]) {
                ++i;
                ++j;
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << x << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}