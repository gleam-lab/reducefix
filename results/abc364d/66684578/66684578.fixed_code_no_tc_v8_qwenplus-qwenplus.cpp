#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vi a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Sort A for binary search in queries
    sort(a.begin(), a.end());

    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;

        // We will use binary search on answer
        ll low = 0, high = 2e8 + 10; // max possible distance + some buffer

        while (low < high) {
            ll mid = (low + high) / 2;

            // Find range of elements within distance `mid` from b
            int left = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int right = upper_bound(a.begin(), a.end(), b + mid) - a.begin();

            if (right - left >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }

    return 0;
}