#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // Initialize variables to keep track of the last character and the count of operations
    char last_char = 'N'; // Initial state
    int count = 0;

    for (char c : S) {
        if (c != last_char) {
            last_char = c;
        } else {
            // If the current character is the same as the last one, increment the count
            ++count;
        }
    }

    // The result is the total number of characters minus the count of consecutive identical characters
    cout << N - count << '\n';

    return 0;
}