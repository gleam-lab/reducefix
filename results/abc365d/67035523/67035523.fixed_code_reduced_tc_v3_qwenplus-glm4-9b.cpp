#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> counts;
    counts['R'] = 0;
    counts['P'] = 0;
    counts['S'] = 0;

    // Count the occurrences of 'R', 'P', and 'S'
    for (char c : s) {
        if (c == 'R') {
            counts['R']++;
        } else if (c == 'P') {
            counts['P']++;
        } else if (c == 'S') {
            counts['S']++;
        }
    }

    // Calculate the maximum number of wins
    int max_wins = max(counts['R'], max(counts['P'], counts['S']));

    // Output the result
    cout << max_wins << endl;

    return 0;
}