#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n + 1);
    vector<long long> a(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        a[i] = a[i - 1] + p;
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int left = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        int right = upper_bound(x.begin() + 1, x.end(), r) - x.begin() - 1;
        
        if (left <= right && left <= n && right <= n) {
            cout << a[right] - a[left - 1] << '\n';
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}