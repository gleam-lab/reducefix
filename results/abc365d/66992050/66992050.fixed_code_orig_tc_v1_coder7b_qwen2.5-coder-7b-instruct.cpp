#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    // Initialize variables
    int count = 0;
    int current = 0;
    
    // Iterate through the string
    for (char c : S) {
        if (c == 'P') {
            count += current;
            current = 0;
        } else {
            current++;
        }
    }
    
    // Add the remaining count
    count += current;
    
    // Output the result
    cout << count << endl;
    
    return 0;
}