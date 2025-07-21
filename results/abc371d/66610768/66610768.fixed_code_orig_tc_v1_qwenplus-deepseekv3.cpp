#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    vector<ll> prefix(n+1, 0);
    
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        prefix[i] = prefix[i-1] + b[i];
    }
    
    int m;
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        int left = lower_bound(a.begin()+1, a.end(), l) - a.begin();
        int right = upper_bound(a.begin()+1, a.end(), r) - a.begin();
        
        ll sum = prefix[right-1] - prefix[left-1];
        cout << sum << '\n';
    }
    
    return 0;
}