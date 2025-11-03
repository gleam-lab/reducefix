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
    
    int ans = 1; // At least one move is needed
    char current_hand = win(s[0]); // First required hand
    
    for (int i = 1; i < n; i++) {
        char needed_hand = win(s[i]);
        if (needed_hand != current_hand) {
            ans++;
            current_hand = needed_hand;
        }
    }
    
    cout << ans << endl;
    return 0;
}