#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define repn(i, x) for(int i = 1; i <= (int)(x); i++)
#define repo(i, x) for(int i = x - 1; i >= 0; i--)
#define sp(i) fixed << setprecision(i)
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int res = a[n - 1] - a[0]; // Initialize with the worst possible difference

    // Check combinations of removing i elements from the start and k - i from the end
    for (int i = 0; i <= k; i++) {
        int j = k - i;
        int current_min = a[i];
        int current_max = a[n - 1 - j];
        res = min(res, current_max - current_min);
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}