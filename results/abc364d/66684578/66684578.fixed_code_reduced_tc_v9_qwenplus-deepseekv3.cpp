#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    rep(i, q) {
        ll b, k;
        cin >> b >> k;
        ll left = 0, right = 2e18;
        ll answer = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            auto lower = lower_bound(a.begin(), a.end(), b - mid);
            auto upper = upper_bound(a.begin(), a.end(), b + mid);
            ll count = upper - lower;
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}