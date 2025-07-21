#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // dummy
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int dp[3] = {0}; // 0: R, 1: P, 2: S
    for (char c : s) {
        int new_dp[3] = {0};
        char w = win(c);
        for (int last = 0; last < 3; ++last) {
            for (int current = 0; current < 3; ++current) {
                char current_move;
                if (current == 0) current_move = 'R';
                else if (current == 1) current_move = 'P';
                else current_move = 'S';
                
                int add = (current_move == w) ? 1 : 0;
                new_dp[current] = max(new_dp[current], dp[last] + add);
            }
        }
        for (int i = 0; i < 3; ++i) {
            dp[i] = new_dp[i];
        }
    }
    
    cout << *max_element(dp, dp + 3) << endl;
    return 0;
}