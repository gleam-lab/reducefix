#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
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
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 1; // At least one move is needed
    char current_strategy = win(s[0]); // First move must counter the first gesture
    
    for (int i = 1; i < n; i++) {
        char opponent_gesture = s[i];
        char needed_move = win(opponent_gesture);
        
        if (needed_move != current_strategy) {
            ans++;
            current_strategy = needed_move;
        }
    }
    
    cout << ans << endl;
    return 0;
}