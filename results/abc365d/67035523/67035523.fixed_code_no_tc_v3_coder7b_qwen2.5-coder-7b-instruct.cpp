#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0;
    char last_move = 'X'; // Initialize with a value that won't be in the string
    
    for (int i = 0; i < n; ++i) {
        if (last_move == 'X' || s[i] != last_move) {
            ++ans;
            // Cycle through R -> P -> S -> R ...
            last_move = (last_move == 'R') ? 'P' : ((last_move == 'S') ? 'R' : 'S');
        } else {
            // If Takahashi plays the same as Aoki, change his next move
            last_move = (last_move == 'R') ? 'P' : ((last_move == 'S') ? 'R' : 'S');
        }
    }
    
    cout << ans << endl;
    return 0;
}