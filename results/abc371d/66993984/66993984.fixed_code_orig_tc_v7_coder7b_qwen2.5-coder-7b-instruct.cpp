#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q;
vector<long long> x(MAXN), p(MAXN);
vector<long long> prefix_sum(MAXN);

void preprocess() {
    prefix_sum[0] = 0;
    for(int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }
}

long long query(int l, int r) {
    return prefix_sum[r] - prefix_sum[l - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    preprocess();

    while(q--) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << '\n';
    }

    return 0;
}