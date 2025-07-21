#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + c[i-1];
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_it = lower_bound(a.begin()+1, a.end(), l);
        auto r_it = upper_bound(a.begin()+1, a.end(), r);
        
        int left_idx = l_it - a.begin();
        int right_idx = r_it - a.begin() - 1;
        
        if(left_idx > right_idx) {
            cout << 0 << endl;
        } else if(right_idx >= n) {
            cout << c[n] - c[left_idx-1] << endl;
        } else {
            cout << c[right_idx] - c[left_idx-1] << endl;
        }
    }
    return 0;
}