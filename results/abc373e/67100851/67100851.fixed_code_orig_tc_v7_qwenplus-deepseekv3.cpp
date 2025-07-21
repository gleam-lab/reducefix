#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    ll total = 0;
    for (ll a : sortedA) {
        total += a;
    }
    ll remaining = K - total;

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        int pos = upper_bound(sortedA.begin(), sortedA.end(), a) - sortedA.begin();
        int l = N - M;
        if (pos > l) {
            res[i] = 0;
            continue;
        }

        ll low = 0, high = remaining;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a + mid;
            int new_pos = upper_bound(sortedA.begin(), sortedA.end(), new_a) - sortedA.begin();
            if (new_pos > l) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}