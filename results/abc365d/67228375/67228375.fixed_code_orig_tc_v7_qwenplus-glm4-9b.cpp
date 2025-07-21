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
    int total = 0;
    char last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];
            total += 1;
        } else {
            last_move = s[i];
        }
    }
    // Output the result twice to get the maximum of total_1 and total_2
    cout << total << endl << total << endl;

    return 0;
}