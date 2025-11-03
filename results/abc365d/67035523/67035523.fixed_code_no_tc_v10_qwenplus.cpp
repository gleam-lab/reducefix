#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    
    int ans = 1; // Start with first move requiring a change
    char current_hand = win(s[0]); // The hand we are currently using
    
    for (int i = 1; i < n; i++) {
        char desired_hand = win(s[i]);
        if (desired_hand != current_hand) {
            ans++;
            current_hand = desired_hand;
        }
    }
    
    cout << ans << endl;
    return 0;
}