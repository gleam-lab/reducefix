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
        if (c == 'P') {
            if (past == 'N' || past == 'R') {
                ans++;
                past = 'P';
            } else {
                past = 'P';
            }
        }
        if (c == 'R') {
            if (past == 'N' || past == 'S') {
                ans++;
                past = 'R';
            } else {
                past = 'R';
            }
        }
        if (c == 'S') {
            if (past == 'N' || past == 'P') {
                ans++;
                past = 'S';
            } else {
                past = 'S';
            }
        }
    }
    cout << ans;
    return 0;
}