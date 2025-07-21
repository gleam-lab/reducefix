#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
long long prefix_sum[N];

void preprocess(vector<long long>& a, vector<long long>& prefix_sum) {
    prefix_sum[0] = 0;
    for(int i = 1; i <= a.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    preprocess(a, prefix_sum);

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if(l > r) swap(l, r);
        cout << prefix_sum[r + 1] - prefix_sum[l] << '\n';
    }

    return 0;
}