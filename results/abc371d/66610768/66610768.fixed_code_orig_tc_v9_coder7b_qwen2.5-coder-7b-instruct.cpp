#include <bits/stdc++.h>
using namespace std;

using LL = __int128;
const int N = 1e6 + 7;

vector<LL> prefix_sum;

void preprocess(const vector<int>& arr) {
    prefix_sum.resize(arr.size() + 1);
    prefix_sum[1] = arr[0];
    for(int i = 2; i <= arr.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    preprocess(b);

    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << b[l - 1] << '\n';
        } else {
            auto l_it = lower_bound(a.begin(), a.end(), l);
            auto r_it = upper_bound(a.begin(), a.end(), r);
            int i = distance(a.begin(), l_it);
            int j = distance(a.begin(), r_it) - 1;
            if(i == j) {
                cout << prefix_sum[j + 1] - prefix_sum[i] << '\n';
            } else {
                cout << prefix_sum[j + 1] - prefix_sum[i] + b[r - 1] - b[l - 1] << '\n';
            }
        }
    }

    return 0;
}