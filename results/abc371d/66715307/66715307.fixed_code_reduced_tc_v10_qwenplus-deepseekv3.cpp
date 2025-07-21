#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> elements[i].second;
    }
    
    sort(elements.begin(), elements.end());
    
    vector<int> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        x[i] = elements[i].first;
        p[i] = elements[i].second;
    }
    
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + p[i - 1];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int left_idx = lower_bound(x.begin(), x.end(), l) - x.begin();
        int right_idx = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
        
        if (left_idx <= right_idx && right_idx < n && left_idx >= 0) {
            cout << prefix[right_idx + 1] - prefix[left_idx] << '\n';
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}