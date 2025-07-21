#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll T = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] <= 0) continue;
        // Calculate the number of full cycles (3 attacks)
        ll full_cycles = h[i] / 5;
        ll remaining = h[i] % 5;

        T += full_cycles * 3;
        h[i] = remaining;

        if (h[i] > 0) {
            if (T % 3 == 0) {
                // Next attack is at T+1, which is not multiple of 3: damage 1
                if (h[i] <= 1) {
                    T += 1;
                    h[i] = 0;
                } else {
                    T += 1;
                    h[i] -= 1;
                    if (h[i] > 0) {
                        // Next attack is T+1, which is not multiple of 3: damage 1
                        if (h[i] <= 1) {
                            T += 1;
                            h[i] = 0;
                        } else {
                            T += 1;
                            h[i] -= 1;
                            if (h[i] > 0) {
                                // Next attack is T+1, which is multiple of 3: damage 3
                                T += 1;
                                h[i] -= 3;
                                if (h[i] > 0) {
                                    // This shouldn't happen as remaining was <5
                                }
                            }
                        }
                    }
                }
            } else {
                // The current T is not a multiple of 3, so next attack is T+1
                // Need to handle the remaining health based on current T mod 3
                ll current_mod = T % 3;
                if (current_mod == 1) {
                    // Next attack is T+1 (mod 2), damage 1
                    if (h[i] <= 1) {
                        T += 1;
                        h[i] = 0;
                    } else {
                        T += 1;
                        h[i] -= 1;
                        // Next attack is T+1 (mod 0), damage 3
                        if (h[i] > 0) {
                            T += 1;
                            h[i] -= 3;
                        }
                    }
                } else if (current_mod == 2) {
                    // Next attack is T+1 (mod 0), damage 3
                    T += 1;
                    h[i] -= 3;
                    if (h[i] > 0) {
                        // Next attack is T+1 (mod 1), damage 1
                        T += 1;
                        h[i] -= 1;
                    }
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}