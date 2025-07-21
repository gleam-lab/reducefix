#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[200011];
    char c[200011];
    
    // Read the string into s[1] to avoid s[0] being unused
    scanf("%s", s + 1);
    
    // Initialize the array c as a copy of s
    for (int i = 1; i <= n; ++i) {
        c[i] = s[i];
    }

    // Variable to keep track of the number of letters that can remain unchanged
    int count = n;

    // Update the array c based on some rule (not clear what the rule is)
    for (int i = 1; i <= n; ++i) {
        // Assuming the rule is: if s[i] == 'P', then c[i] = 'S'; if s[i] == 'R', then c[i] = 'P'; else c[i] = 'R'
        if (s[i] == 'P') {
            c[i] = 'S';
        } else if (s[i] == 'R') {
            c[i] = 'P';
        } else {
            c[i] = 'R';
        }
    }

    // Find sequences of equal characters in c and update them according to some rule
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            count--; // Decrease the count as we can change this character later
        }
    }

    // Output the count of characters that can remain unchanged
    printf("%d\n", count);
    return 0;
}