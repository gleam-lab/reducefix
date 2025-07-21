#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    int i = 0;
    while (i < n) {
        // If at least one more element is available, consider pairing
        if (i + 1 < n) {
            // Choose the better option between:
            // a) taking current and next as a pair with 2x multiplier
            // b) taking current alone with 1x and move to next
            ll pairSum = data[i] * 2 + data[i + 1] * 2;
            ll singleSum = data[i] + data[i + 1];

            if (pairSum > singleSum) {
                sum += data[i] * 2 + data[i + 1] * 2;
                i += 2;
            } else {
                sum += data[i] + data[i + 1];
                i += 2;
            }
        } else {
            // Odd one out - just add it
            sum += data[i];
            i++;
        }
    }

    cout << sum << endl;
    return 0;
}