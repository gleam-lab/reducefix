#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = S[0];
    for (size_t i = 1; i < S.length(); ++i) {
        char current = S[i];
        if (current != prev) {
            wins++;
            prev = current;
        }
    }
    cout << wins + 1; // Add 1 because we start counting from the first move
    return 0;
}