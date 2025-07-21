#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vi a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Sort the A coordinates for binary search usage
    sort(a.begin(), a.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search to find the k-th closest element
        int left = 0;
        int right = N - 1;

        // Find the position in A where B is located (not existing, just insertion point)
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();

        int l = pos - 1;
        int r = pos;

        // We will use two pointers to find the k-th closest distance
        vll distances;
        while (l >= 0 && r < N && distances.size() < static_cast<unsigned int>(k)) {
            if (abs((ll)a[l] - b) <= abs((ll)a[r] - b)) {
                distances.pb(abs((ll)a[l] - b));
                l--;
            } else {
                distances.pb(abs((ll)a[r] - b));
                r++;
            }
        }

        while (l >= 0 && distances.size() < static_cast<unsigned int>(k)) {
            distances.pb(abs((ll)a[l] - b));
            l--;
        }

        while (r < N && distances.size() < static_cast<unsigned int>(k)) {
            distances.pb(abs((ll)a[r] - b));
            r++;
        }

        // The distances are added in order of increasing closeness
        cout << distances[k - 1] << "\n";
    }

    return 0;
}