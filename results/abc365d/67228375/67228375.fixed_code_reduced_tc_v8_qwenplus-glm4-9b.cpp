#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            total_1++;
        }
        last_move = beats[s[i]];
    }

    int total_2 = 1;
    last_move = beats[s[0]];
    for (int i = 0; i < n; i++) {
        if (beats[s[(i + 1) % n]] == last_move) {
            total_2++;
        }
        last_move = beats[s[(i + 1) % n]];
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}