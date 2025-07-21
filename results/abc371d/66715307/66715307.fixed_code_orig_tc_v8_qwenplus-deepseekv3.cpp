#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n+1), p(n+1);
    vector<long long> prefix(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix[i] = prefix[i-1] + p[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Binary search for first x[i] >= l
        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (x[mid] >= l) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        int left_pos = (x[low] >= l) ? low : n + 1;
        
        // Binary search for last x[i] <= r
        low = 1, high = n;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (x[mid] <= r) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        int right_pos = (x[low] <= r) ? low : 0;
        
        if (left_pos > right_pos) {
            cout << "0\n";
        } else {
            cout << prefix[right_pos] - prefix[left_pos - 1] << '\n';
        }
    }
    
    return 0;
}