#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;
    vector<ll> pending_attacks(3, 0); // Attacks that will hit at T mod 3 == 0, 1, 2

    for (ll i = 0; i < n; ++i)
    {
        ll h = H[i];

        // First apply all pending attacks to the current enemy
        for (ll j = 0; j < 3; ++j)
        {
            if (pending_attacks[j] > 0)
            {
                ll use = min(pending_attacks[j], (h + (j == 0 ? 2 : 0)) / (j == 0 ? 3 : 1));
                h -= use * (j == 0 ? 3 : 1);
                pending_attacks[j] -= use;
                T += use;
                if (h <= 0) break;
            }
        }

        // Now handle remaining health
        if (h > 0)
        {
            ll cycles = h / 5;
            ll rem = h % 5;

            T += cycles * 3;
            // Store leftover attacks in buffer
            pending_attacks[0] += cycles;
            pending_attacks[1] += cycles;
            pending_attacks[2] += cycles;

            if (rem > 0)
            {
                T++;
                pending_attacks[T % 3]++;
                h -= (T % 3 == 0 ? 3 : 1);
                if (h > 0)
                {
                    T++;
                    pending_attacks[T % 3]++;
                    h -= (T % 3 == 0 ? 3 : 1);
                }
            }
        }
    }

    // Apply any remaining buffered attacks after last enemy
    T += pending_attacks[0] + pending_attacks[1] + pending_attacks[2];

    cout << T << endl;
    return 0;
}