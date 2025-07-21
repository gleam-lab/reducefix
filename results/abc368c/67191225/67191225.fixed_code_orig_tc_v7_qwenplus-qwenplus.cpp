#include <iostream>
#include <vector>
#include <cmath>
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
        // Each enemy takes at least H[i] / 3 attacks with damage 3, but we have to account for spacing
        // Every attack must be spaced by at least one other attack between attacking same enemy
        // So we need to interleave attacks
        
        // Let's calculate how many total attacks are needed on this enemy
        // For every 3 points of health, it takes 3 turns minimum (1 attack of type 3)
        // But since we can only attack the frontmost alive enemy, each attack is sequential

        // We simulate as follows:
        // - We must attack this enemy H[i] times in some fashion
        // - Every time we attack, it's either -1 or -3 depending on T % 3 == 0
        // - To get a -3 attack, you need to wait until T is divisible by 3

        // Optimal way: alternate between attacks when possible to maximize -3 hits
        // Try to use T % 3 == 0 as often as possible

        ll h = H[i];
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }

    cout << T << endl;
}