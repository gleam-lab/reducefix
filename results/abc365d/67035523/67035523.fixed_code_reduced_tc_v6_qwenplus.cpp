#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
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
    
    int ans = 1; // Start with first move
    char last_played = win(s[0]); // What we played to beat first opponent move
    
    for (int i = 1; i < n; i++) {
        char desired = win(s[i]); // What we need to play to beat current
        
        if (desired != last_played) {
            ans++;
            last_played = desired;
        } else {
            // We can use the same gesture, no additional move needed
            // But we still update our state to reflect we're continuing with this gesture
            // Actually, we don't need to change anything
        }
    }
    
    cout << ans << endl;
    return 0;
}