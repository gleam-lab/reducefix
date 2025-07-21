#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int low = 1, high = 1e9;
    int answer = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        vector<int> boxes = b;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());
        
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] > boxes[i]) {
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