#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int max_switches = 1;
    char last_move = beats[s[0]];
    
    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] != last_move) {
            max_switches++;
            last_move = beats[s[i]];
        }
    }
    
    cout << max_switches << endl;
    
    return 0;
}