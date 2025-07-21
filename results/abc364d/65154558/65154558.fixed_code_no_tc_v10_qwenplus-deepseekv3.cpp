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
        ll b, k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int pos = left;
        vector<ll> distances;
        int i = pos - 1, j = pos;
        for (int count = 0; count < k && (i >= 0 || j < N); ) {
            if (i >= 0 && j < N) {
                if (abs(a[i] - b) <= abs(a[j] - b)) {
                    distances.push_back(abs(a[i] - b));
                    i--;
                    count++;
                } else {
                    distances.push_back(abs(a[j] - b));
                    j++;
                    count++;
                }
            } else if (i >= 0) {
                distances.push_back(abs(a[i] - b));
                i--;
                count++;
            } else {
                distances.push_back(abs(a[j] - b));
                j++;
                count++;
            }
        }
        
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}