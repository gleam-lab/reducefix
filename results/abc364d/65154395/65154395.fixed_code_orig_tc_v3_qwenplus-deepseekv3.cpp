#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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
        k--; // convert to 0-based index

        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (a[mid] < b) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int pos = left;

        int l = pos, r = pos;
        for (int step = 1; step <= N; step *= 2) {
            if (l - step >= 0 && abs(a[l - step] - b) <= abs(a[r] - b)) {
                l -= step;
            }
            if (r + step < N && abs(a[r + step] - b) < abs(a[l] - b)) {
                r += step;
            }
        }

        vector<ll> candidates;
        for (int i = max(0, l - 5); i <= min(N - 1, l + 5); ++i) {
            candidates.push_back(abs(a[i] - b));
        }
        for (int i = max(0, r - 5); i <= min(N - 1, r + 5); ++i) {
            candidates.push_back(abs(a[i] - b));
        }
        sort(candidates.begin(), candidates.end());
        cout << candidates[k] << '\n';
    }

    return 0;
}