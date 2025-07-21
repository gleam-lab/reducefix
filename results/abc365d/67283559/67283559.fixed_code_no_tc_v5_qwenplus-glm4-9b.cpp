#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> validOptions = {'R', 'P', 'S'};
    int totalScore = 0;

    // First pass to determine the possible responses for each character in S
    for (int i = 0; i < N; ++i) {
        char currentChar = S[i];
        vector<char> possibleResponses;

        for (char option : validOptions) {
            if ((option == 'R' && currentChar == 'S') ||
                (option == 'P' && currentChar == 'R') ||
                (option == 'S' && currentChar == 'P')) {
                possibleResponses.push_back(option);
            }
        }

        // Score based on the first valid response, or keep the current character if no valid response exists
        if (!possibleResponses.empty()) {
            totalScore++;
            // Remove the character that was used from the list of valid options for the next iteration
            for (char response : possibleResponses) {
                auto it = find(validOptions.begin(), validOptions.end(), response);
                if (it != validOptions.end()) {
                    validOptions.erase(it);
                }
            }
        }
    }

    // Second pass to evaluate the remaining options after the first pass
    int totalScore2 = 0;

    for (int i = 0; i < N; ++i) {
        char currentChar = S[i];
        vector<char> possibleResponses;

        for (char option : validOptions) {
            if ((option == 'R' && currentChar == 'S') ||
                (option == 'P' && currentChar == 'R') ||
                (option == 'S' && currentChar == 'P')) {
                possibleResponses.push_back(option);
            }
        }

        // Score based on the first valid response, or keep the current character if no valid response exists
        if (!possibleResponses.empty()) {
            totalScore2++;
            // Remove the character that was used from the list of valid options for the next iteration
            for (char response : possibleResponses) {
                auto it = find(validOptions.begin(), validOptions.end(), response);
                if (it != validOptions.end()) {
                    validOptions.erase(it);
                }
            }
        }
    }

    cout << max(totalScore, totalScore2) << endl;

    return 0;
}