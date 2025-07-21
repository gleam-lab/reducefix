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
        bool possible = true;
        int new_box_used = 0;
        int i = n - 1;
        int j = n - 2;
        
        while (i >= 0) {
            if (j >= 0 && B[j] >= A[i]) {
                --j;
                --i;
            } else if (mid >= A[i] && new_box_used == 0) {
                new_box_used = 1;
                --i;
            } else {
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