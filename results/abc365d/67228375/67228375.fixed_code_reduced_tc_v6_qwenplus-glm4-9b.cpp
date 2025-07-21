#include <iostream>
#include <map>
#include <string>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If the string length is less than 2, the maximum possible values of total_1 and total_2 are n
    if (n < 2) {
        cout << n << endl;
        return 0;
    }

    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            total_1++;
        } else {
            last_move = s[i];
            total_1++;
        }
    }
    
    int total_2 = 1;
    last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            total_2++;
        } else {
            last_move = s[i];
            total_2++;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}