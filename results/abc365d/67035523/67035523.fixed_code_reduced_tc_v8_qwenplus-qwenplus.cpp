#include <iostream>
#include <string>
using namespace std;

// Function to determine the outcome of a single RPS move
char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return x; // should never reach here
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char current_move = '\0'; // no move yet

    for (int i = 0; i < n; ++i) {
        char opponent_move = s[i];
        
        // If we can't use the same winning move again, we need to change it
        if (current_move != win(opponent_move)) {
            current_move = win(opponent_move);
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}