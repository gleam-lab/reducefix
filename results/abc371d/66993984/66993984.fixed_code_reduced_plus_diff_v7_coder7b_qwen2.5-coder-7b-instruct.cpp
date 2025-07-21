#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long prefix_sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;
    vector<long long> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        prefix_sum[i] = (i ? prefix_sum[i - 1] : 0) + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        cout << prefix_sum[R] - (L ? prefix_sum[L - 1] : 0) << '\n';
    }

    return 0;
}