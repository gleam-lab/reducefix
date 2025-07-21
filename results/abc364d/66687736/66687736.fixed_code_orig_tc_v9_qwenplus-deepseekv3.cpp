#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;

        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            int left = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int right = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            int count = right - left;

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}