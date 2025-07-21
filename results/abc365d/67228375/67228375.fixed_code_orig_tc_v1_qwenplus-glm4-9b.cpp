#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_1 = 1; // counts the longest sequence of beats starting from index 0
    int total_2 = 0; // counts the longest sequence of beats starting from index 1
    char last_move = beats[s[0]];
    char new_last_move;

    // Start from index 1 to calculate the longest sequence starting from index 1
    for (int i = 1; i < n; i++) {
        new_last_move = beats[s[i]];
        if (last_move == s[i]) {
            last_move = new_last_move;
        } else {
            total_2++;
            last_move = new_last_move;
        }
    }

    // Start from index 0 to calculate the longest sequence starting from index 0
    for (int i = 1; i < n; i++) {
        new_last_move = beats[s[i]];
        if (last_move == s[i]) {
            last_move = new_last_move;
        } else {
            total_1++;
            last_move = new_last_move;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}