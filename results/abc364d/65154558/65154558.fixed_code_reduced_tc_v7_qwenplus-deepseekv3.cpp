#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
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

        int low = 0, high = N - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[mid] < b) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int pos = low;

        int left = pos - 1;
        int right = pos;
        vector<ll> distances;
        for (int i = 0; i < k + 1; ++i) {
            if (left >= 0 && right < N) {
                if (b - a[left] <= a[right] - b) {
                    distances.push_back(b - a[left]);
                    left--;
                } else {
                    distances.push_back(a[right] - b);
                    right++;
                }
            } else if (left >= 0) {
                distances.push_back(b - a[left]);
                left--;
            } else {
                distances.push_back(a[right] - b);
                right++;
            }
        }
        nth_element(distances.begin(), distances.begin() + k, distances.end());
        cout << distances[k] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}