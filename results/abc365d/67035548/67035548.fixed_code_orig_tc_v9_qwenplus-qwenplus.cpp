#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return 'X'; // shouldn't happen
}

int calculate_moves(const string& s, bool reverse_dir = false) {
    int n = s.size();
    int count = 0;
    char last_move = 'X';

    if (!reverse_dir) {
        for (char c : s) {
            char win_move = winning_move(c);
            if (last_move != win_move) {
                count++;
                last_move = win_move;
            } else {
                last_move = c;
            }
        }
    } else {
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            char win_move = winning_move(c);
            if (last_move != win_move) {
                count++;
                last_move = win_move;
            } else {
                last_move = c;
            }
        }
    }

    return count;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int forward = calculate_moves(s, false);
    int backward = calculate_moves(s, true);

    cout << max(forward, backward) << endl;

    return 0;
}