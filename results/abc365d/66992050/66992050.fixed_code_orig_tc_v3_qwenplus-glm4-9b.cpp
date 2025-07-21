#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N;
    string S;
    cin >> N; // N is not used in the code
    string past = "N"; // Changed 'char' to 'string' to handle multiple characters
    int ans = 0;
    for (char c : S) {
        string current = string(1, c); // Convert the char to a string for comparison
        if (past == "N" || past != current) {
            ans++; // Only increment if there's a change or it's the first character
            past = current; // Update past to the current character
        }
    }
    cout << ans;
    return 0;
}