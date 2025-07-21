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
    
    // Initialize the result with the length of the string
    int total_1 = 1;
    char last_move = s[0];

    // Iterate through the string starting from the second character
    for (int i = 1; i < n; i++) {
        if (s[i] != beats[last_move]) {
            last_move = s[i];
            total_1++;
        }
    }

    // Reset last_move to the first character
    last_move = s[n - 1];
    int total_2 = 1;

    // Iterate through the string from the end to the beginning
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != beats[last_move]) {
            last_move = s[i];
            total_2++;
        }
    }

    // Output the maximum of the two counts
    cout << max(total_1, total_2) << endl;

    return 0;
}