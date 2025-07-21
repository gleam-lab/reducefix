#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int wins = 0;
    int losses = 0;
    char prev = s[0];
    
    for (size_t i = 1; i < n; ++i) {
        if ((prev == 'R' && s[i] == 'P') || (prev == 'P' && s[i] == 'S') || (prev == 'S' && s[i] == 'R')) {
            ++wins;
        } else {
            ++losses;
        }
        prev = s[i];
    }
    
    cout << max(wins, losses) << endl;
    
    return 0;
}