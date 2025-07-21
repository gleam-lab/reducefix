#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return 'X'; // invalid
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    char last_played = 'X'; // initially invalid

    for (char c : s) {
        if (last_played != winning_move(c)) {
            count++;
            last_played = winning_move(c);
        } else {
            last_played = c;
        }
    }

    cout << count << endl;
}