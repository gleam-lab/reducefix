#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<ll> suffix_sum(N + 1);
    suffix_sum[N] = 0;
    for (int i = N - 1; i >= 0; i--)
        suffix_sum[i] = suffix_sum[i + 1] + A[i];

    for (int i = 0; i < N; i++) {
        ll target = A[i] + 1;
        int left = 0, right = N - 1;
        int index = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (suffix_sum[mid] < target * (M - mid)) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (index == -1) {
            cout << 0 << " ";
        } else {
            ll needed_votes = target * (M - index) - suffix_sum[index];
            if (needed_votes > K)
                cout << -1 << " ";
            else
                cout << needed_votes << " ";
        }
    }

    cout << endl;
    return 0;
}