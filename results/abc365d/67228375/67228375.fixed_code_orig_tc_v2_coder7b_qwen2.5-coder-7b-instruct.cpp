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
    
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            last_move = beats[s[i]];
            total_1++;
        }
    }

    int total_2 = 1;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != last_move) {
            last_move = s[i];
            total_2++;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}