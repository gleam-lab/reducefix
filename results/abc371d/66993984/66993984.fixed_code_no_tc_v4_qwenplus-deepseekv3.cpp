#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    vector<int> sum(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        int d = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        if(c >= d) {
            cout << 0 << endl;
        } else {
            cout << sum[d - 1] - sum[c - 1] << endl;
        }
    }
    return 0;
}