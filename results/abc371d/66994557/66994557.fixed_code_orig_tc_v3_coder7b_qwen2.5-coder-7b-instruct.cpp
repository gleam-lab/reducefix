#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        if(L == R) {
            cout << p[L] << '\n';
        } else {
            cout << sum[R] - sum[L-1] << '\n';
        }
    }
    return 0;
}