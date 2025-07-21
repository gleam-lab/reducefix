#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    unordered_map<char, char> transitions = {{'P', 'S'}, {'R', 'P'}, {'S', 'R'}};
    char last_char = S[0];
    int count = 0;

    for (size_t i = 1; i < S.size(); ++i) {
        if (transitions[last_char] == S[i]) {
            count++;
        }
        last_char = S[i];
    }

    cout << count << endl;
    return 0;
}