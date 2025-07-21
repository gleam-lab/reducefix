#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<long long> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<long long> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        long long target = k / (n - i - m);
        if(target >= a[ord[i]]) {
            ans[ord[i]] = target - a[ord[i]];
        }
    }

    for(int i = 0; i < n; ++i) {
        if(ans[i] == -1) continue;
        long long need = ans[i];
        if(need + a[ord[i]] <= pref[n]) {
            ans[ord[i]] = need;
        } else {
            ans[ord[i]] = -1;
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}