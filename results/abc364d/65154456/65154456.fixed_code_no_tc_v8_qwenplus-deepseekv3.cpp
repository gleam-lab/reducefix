#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
        k--; // Convert to 0-based index

        // Binary search to find the k-th closest point
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Now, left is the first index where a[i] > b
        int l = right;
        int r = left;
        vector<ll> distances;
        int i = l, j = r;
        for (int cnt = 0; cnt < k + 1; ) {
            ll dist_left = (i >= 0) ? abs(a[i] - b) : LLONG_MAX;
            ll dist_right = (j < N) ? abs(a[j] - b) : LLONG_MAX;
            if (dist_left < dist_right) {
                distances.push_back(dist_left);
                i--;
                cnt++;
            } else if (dist_left > dist_right) {
                distances.push_back(dist_right);
                j++;
                cnt++;
            } else {
                distances.push_back(dist_left);
                i--;
                cnt++;
                if (cnt < k + 1) {
                    distances.push_back(dist_right);
                    j++;
                    cnt++;
                }
            }
        }

        nth_element(distances.begin(), distances.begin() + k, distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}