#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // for completeness
}

int compute_max_win(const string& s, int n, bool reverse_dir = false) {
    int count = 0;
    char last_move = 'X';

    vector<char> seq = s;
    if (reverse_dir) {
        ::reverse(seq.begin(), seq.end());
    }

    for (char c : seq) {
        char desired = win(c);
        if (desired != last_move) {
            count++;
            last_move = desired;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int forward = compute_max_win(s, n);
    int backward = compute_max_win(s, n, true);

    cout << max(forward, backward) << endl;

    return 0;
}