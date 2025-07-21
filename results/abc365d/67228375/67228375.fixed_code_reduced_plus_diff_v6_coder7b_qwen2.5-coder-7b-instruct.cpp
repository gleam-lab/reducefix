#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Count the number of consecutive moves that can be won
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] != s[i-1]) {
            count++;
        } else {
            break;
        }
    }
    
    // The result is the maximum of the count of winning moves and the length of the sequence minus one
    cout << max(count, n - 1) << endl;

    return 0;
}