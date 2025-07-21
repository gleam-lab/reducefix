#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return x; // for 'X' or any other character
}

int compute_max_wins(const string& s) {
    int n = s.size();
    int count = 0;
    char last_move = 'X'; // initially invalid move

    for (int i = 0; i < n; ++i) {
        char next_move = win(s[i]);
        if (next_move != last_move) {
            count++;
            last_move = next_move;
        }
    }

    return count;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Compute optimal wins from left to right
    int left_to_right = compute_max_wins(s);

    // Compute optimal wins from right to left
    reverse(s.begin(), s.end());
    int right_to_left = compute_max_wins(s);

    cout << max(left_to_right, right_to_left) << endl;

    return 0;
}