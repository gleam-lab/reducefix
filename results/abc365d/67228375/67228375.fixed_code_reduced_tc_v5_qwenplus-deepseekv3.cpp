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
    
    int max_wins = 1;
    char last_move = beats[s[0]];
    
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            last_move = beats[s[i]];
            max_wins++;
        }
    }
    
    cout << max_wins << endl;

    return 0;
}