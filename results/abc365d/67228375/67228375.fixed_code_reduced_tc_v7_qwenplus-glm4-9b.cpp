#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s(n, 0); // Initialize string to ensure proper behavior with cin
    cin >> s;

    int total_1 = 1;
    char last_move = beats[s[0]];

    // Calculate total_1 by iterating through the string
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];
            total_1 += 1;
        }
    }

    // Calculate total_2 by iterating through the string
    int total_2 = 0;
    char start = s[0]; // Start with the first character
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == s[i - 1]) {
            s[i] = s[i - 1];
            total_2 += 1;
        }
    }
    
    // Since total_2 counts all pairs that can beat the previous character, we need to subtract 1
    // because the last character is always paired with itself
    cout << max(total_1, total_2 - 1) << endl;

    return 0;
}