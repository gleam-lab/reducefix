#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), b(n+1), prefix(n+1);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        prefix[i] = prefix[i-1] + b[i];
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        int left = lower_bound(a.begin()+1, a.end(), l) - a.begin();
        int right = upper_bound(a.begin()+1, a.end(), r) - a.begin() - 1;
        
        if(left > right) {
            cout << 0 << endl;
        } else {
            cout << prefix[right] - prefix[left-1] << endl;
        }
    }
    return 0;
}