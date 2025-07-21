#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int wins = 0;
    char last_move = 'X';

    for (int i = 0; i < n; ++i) {
        if (last_move == 'X' || s[i] == last_move) {
            wins++;
            last_move = (s[i] == 'R') ? 'P' : (s[i] == 'P') ? 'S' : 'R';
        }
    }

    cout << wins << endl;
    return 0;
}