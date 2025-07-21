#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = 'N';
    int ans = 0;

    for (char c : S) {
        if (c == 'P' || c == 'R' || c == 'S') {
            if (past == 'N') {  // Initial state is set, first valid operation starts
                ans++;
            }
            past = c;  // Update the past state to current state
        }
    }

    cout << ans;
    return 0;
}