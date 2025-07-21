#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; ++i) {
        ll hi = H[i];
        // We need to find the minimal k such that k + 2 * (k / 3) >= hi
        // Binary search for k
        ll low = 0, high = hi * 2;
        ll k = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = mid + 2 * (mid / 3);
            if (damage >= hi) {
                high = mid - 1;
                k = mid;
            } else {
                low = mid + 1;
            }
        }
        // Adjust T to the point where the k-th attack is performed
        T += k;
        // The actual T after all k attacks is T_init + k
        // But since T is cumulative, we need to ensure we don't recount previous attacks
        // So after each enemy, T is the total time up to now
    }
    cout << T << endl;
    return 0;
}