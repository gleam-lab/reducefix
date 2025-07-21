#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll calculate_min_time(ll H) {
    ll low = 0;
    ll high = 2 * H; // A safe upper bound
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = 3 * (mid / 3) + (mid % 3);
        if (damage >= H) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    ll T = 0;
    ll total_time = 0;
    for (int i = 0; i < N; i++) {
        ll H_i = H[i];
        ll low = 0;
        ll high = 2 * H_i;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll damage = 3 * (mid / 3) + (mid % 3);
            if (damage >= H_i) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        ll T_i = low;
        total_time += T_i;
    }
    cout << total_time << endl;
    return 0;
}