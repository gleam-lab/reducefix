#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 1; // At least one move is needed for the first gesture
    char current_hands = win(s[0]); // Our hand that beats the first opponent's move
    
    for (int i = 1; i < n; i++) {
        char needed_hand = win(s[i]);
        if (needed_hand != current_hands) {
            ans++;
            current_hands = needed_hand;
        }
    }
    
    cout << ans << endl;
    return 0;
}