#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN], sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;

        auto itL = lower_bound(x + 1, x + n + 1, L);
        auto itR = upper_bound(x + 1, x + n + 1, R);

        int idxL = itL - x;
        int idxR = itR - x;

        if(idxL > n || idxR < 1) {
            cout << 0 << '\n';
        } else {
            cout << sum[min(n, idxR - 1)] - sum[max(0, idxL - 2)] << '\n';
        }
    }

    return 0;
}