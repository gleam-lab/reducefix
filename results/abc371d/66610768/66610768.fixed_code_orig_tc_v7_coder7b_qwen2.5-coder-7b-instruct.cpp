#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), prefix_sum(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        --l; --r; // Adjusting index to be zero-based
        ll sum = prefix_sum[r + 1] - prefix_sum[l];
        cout << sum << '\n';
    }
    
    return 0;
}