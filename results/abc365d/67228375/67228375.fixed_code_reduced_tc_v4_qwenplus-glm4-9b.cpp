#include <iostream>
#include <map>
#include <string>
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

    // Initialize variables
    int max_1 = 0, max_2 = 0;
    char pattern = s[0];
    int count_1 = 1, count_2 = 1;

    // First pass to count consecutive patterns
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == pattern) {
            pattern = s[i];
            count_1++;
        } else {
            max_1 = max(max_1, count_1);
            count_1 = 1;
            pattern = s[i];
        }
    }
    max_1 = max(max_1, count_1); // To consider the last pattern sequence

    // Second pass to count consecutive non-patterns
    pattern = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != pattern) {
            pattern = s[i];
            count_2++;
        } else {
            max_2 = max(max_2, count_2);
            count_2 = 1;
            pattern = s[i];
        }
    }
    max_2 = max(max_2, count_2); // To consider the last pattern sequence

    // Output the maximum value from both passes
    cout << max(max_1, max_2) << endl;

    return 0;
}