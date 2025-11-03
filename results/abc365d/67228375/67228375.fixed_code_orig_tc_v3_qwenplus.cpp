#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Try both starting options: either start with the beat of first move or the first move itself
    auto countTransitions = [&](char start) {
        int total = 1;
        char last = start;
        for (int i = 0; i < n; i++) {
            if (beats[s[i]] == last) {
                // We can continue the current round without a new transition
                last = s[i];
            } else {
                // Need to start a new round
                total++;
                last = beats[s[i]];
            }
        }
        return total;
    };

    // Two possibilities: 
    // 1. First round ends with the move that beats s[0]
    // 2. First round ends with s[0] itself (so next must beat s[0])
    int total1 = countTransitions(beats[s[0]]);
    int total2 = countTransitions(s[0]);

    cout << max(total1, total2) << endl;

    return 0;
}