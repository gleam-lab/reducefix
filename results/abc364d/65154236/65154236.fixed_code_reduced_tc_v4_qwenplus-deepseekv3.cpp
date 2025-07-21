#include<bits/stdc++.h>
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
        int left = 0, right = N - 1;
        // Binary search to find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        // We need to collect k elements closest to b
        vector<ll> distances;
        int i = pos - 1, j = pos;
        int count = 0;
        while (count < k && (i >= 0 || j < N)) {
            if (i >= 0 && j < N) {
                if (abs(a[i] - b) <= abs(a[j] - b)) {
                    distances.push_back(abs(a[i] - b));
                    i--;
                } else {
                    distances.push_back(abs(a[j] - b));
                    j++;
                }
            } else if (i >= 0) {
                distances.push_back(abs(a[i] - b));
                i--;
            } else {
                distances.push_back(abs(a[j] - b));
                j++;
            }
            count++;
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}