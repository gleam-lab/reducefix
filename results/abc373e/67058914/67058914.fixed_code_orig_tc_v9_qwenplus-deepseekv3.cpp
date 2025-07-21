#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<ll>());

    ll total = accumulate(A.begin(), A.end(), 0LL);
    ll remaining = K - total;

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a + mid;
            
            // Find the position of new_a in the sorted array
            auto it = upper_bound(sortedA.begin(), sortedA.end(), new_a, greater<ll>());
            int pos = it - sortedA.begin();
            
            // Calculate the remaining votes needed to ensure at most M-1 candidates have votes > new_a
            ll needed = 0;
            if (pos > 0) {
                needed = new_a * pos - prefix[pos];
            }
            
            if (sortedA[pos] == new_a) {
                // If there are duplicates, count them correctly
                while (pos < N && sortedA[pos] == new_a) {
                    pos++;
                }
                needed = new_a * pos - prefix[pos];
            } else {
                needed = new_a * pos - prefix[pos];
            }
            
            // The number of candidates with votes > new_a is pos
            // We need pos <= M - 1
            if (pos <= M - 1) {
                ans = mid;
                high = mid - 1;
            } else {
                // Check if we can distribute remaining votes to make pos <= M - 1
                if (needed <= remaining - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}