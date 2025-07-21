#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, Q;
    cin >> N >> Q;
    vi a(N);
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        ll b, k;
        cin >> b >> k;
        auto pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        
        ll left = pos - 1;
        ll right = pos;
        vi closest;
        
        while (closest.size() < k && (left >= 0 || right < N)) {
            if (left >= 0 && right < N) {
                if (abs(a[left] - b) <= abs(a[right] - b)) {
                    closest.push_back(a[left]);
                    left--;
                } else {
                    closest.push_back(a[right]);
                    right++;
                }
            } else if (left >= 0) {
                closest.push_back(a[left]);
                left--;
            } else {
                closest.push_back(a[right]);
                right++;
            }
        }
        
        nth_element(closest.begin(), closest.begin() + (k - 1), closest.end(), [b](ll x, ll y) {
            if (abs(x - b) != abs(y - b)) {
                return abs(x - b) < abs(y - b);
            }
            return x < y;
        });
        
        cout << abs(closest[k - 1] - b) << '\n';
    }

    return 0;
}