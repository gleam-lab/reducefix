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
    
    int ans = 1; // Start with first gesture counted
    char last_played = win(s[0]); // First move must be the winning move against opponent's first
    
    for (int i = 1; i < n; i++) {
        char desired = win(s[i]);
        // If we can continue using the same gesture as previous, do it
        if (desired == last_played) {
            continue; // Same gesture works for current round too
        } else {
            // Need to switch gesture
            ans++;
            last_played = desired;
        }
    }
    
    cout << ans << endl;
    return 0;
}