#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // shouldn't happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 1; // At least one round is needed
    char current_hand = win(s[0]); // The hand we need to play in current round
    
    for (int i = 1; i < n; i++) {
        char required_hand = win(s[i]);
        
        // If we can't use the same hand for both current and previous opponent moves
        if (required_hand != current_hand) {
            ans++;
            current_hand = required_hand;
        }
        // Otherwise, we continue with the same hand
    }
    
    cout << ans << endl;
    return 0;
}