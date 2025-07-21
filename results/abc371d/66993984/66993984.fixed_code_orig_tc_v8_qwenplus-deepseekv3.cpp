#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n;
    vector<int> x(n+1);
    vector<ll> prefix_sum(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        prefix_sum[i] = prefix_sum[i-1] + p;
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        int first = lower_bound(x.begin()+1, x.end(), L) - x.begin();
        int last = upper_bound(x.begin()+1, x.end(), R) - x.begin();
        cout << prefix_sum[last-1] - prefix_sum[first-1] << '\n';
    }
    
    return 0;
}