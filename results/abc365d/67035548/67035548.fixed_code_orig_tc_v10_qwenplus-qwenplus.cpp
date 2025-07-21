#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Placeholder for invalid input
}

int solve(const string& s) {
    int n = s.size();
    vector<int> forward(n), backward(n);
    
    // Forward pass
    int count = 0;
    char last_move = 'X';
    for (int i = 0; i < n; ++i) {
        char desired = win(s[i]);
        if (desired != last_move) {
            ++count;
            last_move = desired;
        }
        forward[i] = count;
    }

    // Backward pass
    count = 0;
    last_move = 'X';
    for (int i = n - 1; i >= 0; --i) {
        char desired = win(s[i]);
        if (desired != last_move) {
            ++count;
            last_move = desired;
        }
        backward[i] = count;
    }

    // Find max overlap
    int max_result = max(forward.back(), backward.front());
    for (int i = 0; i < n - 1; ++i) {
        if (win(s[i]) != win(s[i + 1])) {
            max_result = max(max_result, forward[i] + backward[i + 1]);
        } else {
            // Need to ensure continuity is maintained
            char move = win(s[i]);
            int j = i + 1;
            while (j < n && win(s[j]) == move) ++j;
            if (j < n) {
                max_result = max(max_result, forward[i] + backward[j]);
            } else {
                max_result = max(max_result, forward[i]);
            }
        }
    }

    return max_result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(s) << endl;
    return 0;
}