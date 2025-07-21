#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return 'X'; // Placeholder for invalid character
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int win_count = 0;
    char last_played = 'X'; // Start with something not in the game

    for (char c : s) {
        if (winning_move(c) != last_played) {
            win_count++;
            last_played = winning_move(c);
        } else {
            last_played = c;
        }
    }

    cout << win_count << endl;

    return 0;
}