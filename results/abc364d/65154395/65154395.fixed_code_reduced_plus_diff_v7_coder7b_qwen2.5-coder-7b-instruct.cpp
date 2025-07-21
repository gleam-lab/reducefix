#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<int> a(n), b(q);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q; ++i) cin >> b[i];

    sort(a.begin(), a.end());

    for(int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        
        int target_index = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int left_count = target_index - 1;
        int right_count = n - target_index;
        
        if(k == left_count + 1) {
            cout << abs(b[i] - a[target_index - 1]) << '\n';
        } else if(k == right_count + 1) {
            cout << abs(b[i] - a[target_index]) << '\n';
        } else {
            cout << min(abs(b[i] - a[target_index - 1]), abs(b[i] - a[target_index])) << '\n';
        }
    }

    return 0;
}