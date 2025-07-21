#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0; // Initialize the count of changes
    char current = 'N'; // Initialize the current state

    for (char c : S) {
        // Determine the next state based on the current and the character
        switch (current) {
            case 'N':
                if (c == 'P') {
                    current = 'P';
                } else if (c == 'S') {
                    current = 'S';
                    ans++; // Increment the count only when changing from N to S
                }
                break;
            case 'P':
                if (c == 'S') {
                    current = 'S';
                    ans++; // Increment the count only when changing from P to S
                } else if (c == 'R') {
                    current = 'R';
                }
                break;
            case 'S':
                if (c == 'R') {
                    current = 'R';
                    ans++; // Increment the count only when changing from S to R
                } else if (c == 'P') {
                    current = 'P';
                }
                break;
        }
    }

    cout << ans << endl;
    return 0;
}