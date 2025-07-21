#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    string s;
    cin >> s;

    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move || s[i] == last_move) {
            last_move = s[i];
            continue;
        }
        total_1++;
        last_move = beats[s[i]];
    }
    int total_2 = 1;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move || s[i] == last_move) {
            last_move = s[i];
            continue;
        }
        total_2++;
        last_move = beats[s[i]];
    }
    cout << max(total_1, total_2) << endl;

    return 0;
}