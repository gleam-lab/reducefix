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
    
    // Calculate the maximum number of moves where no two consecutive moves are the same
    int total_1 = 1;
    char last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != last_move) {
            last_move = s[i];
            total_1 += 1;
        }
    }

    // Since we can always choose the opposite move to maximize the length, the result is at most n
    cout << min(n, total_1 + 1) << endl;

    return 0;
}