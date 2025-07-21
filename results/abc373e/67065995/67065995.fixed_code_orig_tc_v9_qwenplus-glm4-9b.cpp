#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    // Sort candidates based on their votes
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        // The position of the M-th highest vote getter
        int mid = n - m;
        if (n - m <= 0) {
            // If there's no M-th highest vote getter, all candidates can be elected
            ans[i] = 0;
            continue;
        }
        // Binary search to find the minimum votes needed
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (prefix[mid - 1] - prefix[i] + a[i] >= mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        ans[i] = l;
    }

    for (auto &v : ans) cout << v << ' ';
    cout << endl;

    return 0;
}