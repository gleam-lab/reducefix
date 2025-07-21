#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second

const int N = 2e5 + 10;

int a[N], b[N];
PII sa[N];

int solve(int n, int k, vector<int>& a, vector<int>& b) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (k == 1) {
            // Directly return the maximum product for k=1
            res = max(res, (long long)a[i] * b[i]);
        } else {
            // For k>1, add the current pair to the result
            res += (long long)a[i] * b[i];
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        cout << solve(n, k, a, b) << '\n';
    }
}