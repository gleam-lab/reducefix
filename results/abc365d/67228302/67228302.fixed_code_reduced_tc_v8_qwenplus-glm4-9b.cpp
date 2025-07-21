#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    string s;
    cin >> n;
    cin >> s;
    int total = 0;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];
            total++;
        }
    }
    cout << total + 1 << endl;  // Include the first move

    return 0;
}