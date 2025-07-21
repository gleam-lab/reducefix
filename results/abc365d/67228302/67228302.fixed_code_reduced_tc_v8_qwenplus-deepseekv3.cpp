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
    int changes = 0;
    for (int i = 1; i < n; i++) {
        if (beats[s[i-1]] == s[i]) {
            changes++;
            // Change s[i] to something that does not beat s[i-1] and is not s[i-1]
            // Also, ensure that the next character (if any) does not get invalidated
            if (i + 1 < n) {
                // Try to set s[i] to a move that doesn't beat s[i-1] and is not beaten by s[i+1]
                // For now, set it to s[i-1] to avoid consecutive beats
                s[i] = s[i-1];
            } else {
                // No next character, just set to s[i-1]
                s[i] = s[i-1];
            }
        }
    }
    cout << changes << endl;

    return 0;
}