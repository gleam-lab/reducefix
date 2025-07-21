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

    // Strategy 1: start with beat of first move
    int total1 = 1;
    char last1 = beats[s[0]];
    for (int i = 1; i < n; ++i) {
        if (s[i] == last1) {
            // opponent played the same as our previous winning move, so continue
            continue;
        }
        if (beats[s[i]] == last1) {
            // opponent played a losing move against our previous move, no change needed
            last1 = s[i];
        } else {
            // need to change our move to beat current opponent move
            last1 = beats[s[i]];
            total1++;
        }
    }

    // Strategy 2: start with original first move
    int total2 = 1;
    char last2 = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] == last2) {
            continue;
        }
        if (beats[s[i]] == last2) {
            last2 = s[i];
        } else {
            last2 = beats[s[i]];
            total2++;
        }
    }

    cout << max(total1, total2) << endl;

    return 0;
}