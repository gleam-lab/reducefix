#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int max_sequences = 0;
    int current_sequence_length = 1;

    for (int i = 1; i < n; i++) {
        // Check if the current character and the previous character form a valid sequence
        if ((s[i] == 'P' && s[i - 1] == 'R') ||
            (s[i] == 'R' && s[i - 1] == 'S') ||
            (s[i] == 'S' && s[i - 1] == 'P')) {
            current_sequence_length++;
        } else {
            // Update the max_sequences if the current sequence is longer
            max_sequences = max(max_sequences, current_sequence_length);
            current_sequence_length = 1; // Reset the length for the next sequence
        }
    }

    // Check the last sequence
    max_sequences = max(max_sequences, current_sequence_length);

    cout << max_sequences << endl;

    return 0;
}