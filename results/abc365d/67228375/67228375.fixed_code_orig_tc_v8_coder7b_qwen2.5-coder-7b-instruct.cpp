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
    
    // Count the number of moves that can be changed to increase the score
    int change_count = 0;
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == s[i-1]) {
            change_count++;
        }
    }

    // The maximum score is the length of the string minus the minimum changes needed
    int max_score = n - change_count;

    cout << max_score << endl;

    return 0;
}