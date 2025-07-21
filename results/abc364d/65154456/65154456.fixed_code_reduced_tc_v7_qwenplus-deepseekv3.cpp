#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
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
        int low = max(0, pos - k);
        int high = min(N - 1, pos + k - 1);
        vector<ll> distances;
        for (int i = low; i <= high; ++i) {
            distances.push_back(abs(a[i] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}