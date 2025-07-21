#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int A[MAXN], B[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= Q; ++i) {
        cin >> B[i] >> A[i];
    }

    sort(A + 1, A + N + 1);
    
    for (int i = 1; i <= Q; ++i) {
        auto it = lower_bound(A + 1, A + N + 1, B[i]);
        int idx = it - A;
        if (idx == 1) cout << abs(A[1] - B[i]) << '\n';
        else if (idx == N) cout << abs(A[N] - B[i]) << '\n';
        else {
            int d1 = abs(A[idx] - B[i]), d2 = abs(A[idx - 1] - B[i]);
            if (d1 <= d2) cout << d1 << '\n';
            else cout << d2 << '\n';
        }
    }
    
    return 0;
}