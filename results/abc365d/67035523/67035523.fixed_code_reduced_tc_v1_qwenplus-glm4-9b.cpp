#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int count = 0;
    char prev = 'X'; // Set to 'X' to handle the case when the first character is 'R', 'S', or 'P'.
    
    for (char c : s) {
        if (c != prev) {
            count++;
            prev = c;
        }
    }
    
    cout << count;
    return 0;
}