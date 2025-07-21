#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n+1), p(n+1);
    vector<ll> prefix_sum(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i-1] + p[i];
    }
    
    int q;
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        int left_pos = lower_bound(x.begin()+1, x.end(), L) - x.begin();
        int right_pos = upper_bound(x.begin()+1, x.end(), R) - x.begin();
        cout << prefix_sum[right_pos-1] - prefix_sum[left_pos-1] << '\n';
    }
    
    return 0;
}