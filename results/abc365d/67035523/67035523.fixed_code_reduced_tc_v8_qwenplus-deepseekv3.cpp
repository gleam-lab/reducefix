#include <iostream>
#include <string>
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
    int ans = 0;
    char prev = 'X'; // Initialize to an invalid character
    
    for (int i = 0; i < n; ++i) {
        char current_win = win(s[i]);
        if (current_win != prev) {
            ans++;
            prev = current_win;
        }
    }
    
    cout << ans << endl;
    return 0;
}