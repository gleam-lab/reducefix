#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case, though not needed per problem statement
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans_left = 0;
    char prev_left = 'X';
    for (int i = 0; i < n; ++i) {
        char current_win = win(s[i]);
        if (current_win != prev_left) {
            ans_left++;
            prev_left = current_win;
        }
    }
    
    int ans_right = 0;
    char prev_right = 'X';
    for (int i = n - 1; i >= 0; --i) {
        char current_win = win(s[i]);
        if (current_win != prev_right) {
            ans_right++;
            prev_right = current_win;
        }
    }
    
    cout << max(ans_left, ans_right) << endl;
    
    return 0;
}