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
    
    // First, calculate the maximum number of stones that will be left after each turn
    int max_stones = n;
    for (int i = 0; i < n; i++) {
        // Find the next beats point
        int next_beat_index = -1;
        for (int j = i + 1; j < n; j++) {
            if (beats[s[j]] == s[i]) {
                next_beat_index = j;
                break;
            }
        }
        if (next_beat_index == -1) {
            // If no beats point is found, the rest of the sequence is the same
            break;
        }
        // Calculate the number of stones between the current beat and the next beat
        int stones_between = next_beat_index - i - 1;
        max_stones = min(max_stones, stones_between);
        i = next_beat_index;
    }
    
    // Output the maximum number of stones that will be left
    cout << max_stones << endl;

    return 0;
}