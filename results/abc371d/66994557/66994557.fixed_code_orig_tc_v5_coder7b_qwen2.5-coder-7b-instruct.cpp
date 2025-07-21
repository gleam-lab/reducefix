#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> x, p, prefix_sum;

int main() {
    cin >> n;
    x.resize(n + 1);
    p.resize(n + 1);
    prefix_sum.resize(n + 1);

    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];

    prefix_sum[1] = p[1];
    for(int i = 2; i <= n; ++i) 
        prefix_sum[i] = prefix_sum[i - 1] + p[i];

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        if(L == R) {
            cout << p[L] << '\n';
        } else {
            cout << prefix_sum[R] - prefix_sum[L - 1] << '\n';
        }
    }

    return 0;
}