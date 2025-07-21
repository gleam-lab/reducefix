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
    string s;
    cin >> s;

    bool switch_happened = false;
    char last_move = ' ';
    int total_1 = 1;

    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == last_move) {
            total_1++;
        } else {
            last_move = s[i];
            switch_happened = true;
        }
    }

    if (!switch_happened) {
        // If no switch has happened, the second total will be the same as the first.
        cout << total_1 << endl;
    } else {
        int total_2 = 1;
        last_move = s[0];
        for (int i = 1; i < n; ++i) {
            if (beats[s[i]] == last_move) {
                total_2++;
            } else {
                last_move = s[i];
                break;
            }
        }
        cout << max(total_1, total_2) << endl;
    }

    return 0;
}