#include<bits/stdc++.h>
using namespace std;
char s[200011];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    
    // Step 1: Transform the characters in `s`
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'P') s[i] = 'S';
        else if(s[i] == 'R') s[i] = 'P';
        else s[i] = 'R';
    }
    
    // Step 2: Iterate through the transformed array and count the segments
    int ans = 0, count = 1, max_count = 1;
    for(int i = 2; i <= n; ++i) {
        if(s[i] == s[i - 1]) {
            count++;
        } else {
            max_count = max(max_count, count);
            count = 1;
        }
    }
    max_count = max(max_count, count);
    ans += max_count;
    
    // If the first two characters are the same, consider the segment from the third character onwards
    if(s[1] == s[2]) {
        count = 1;
        for(int i = 3; i <= n; ++i) {
            if(s[i] == s[i - 1]) {
                count++;
            } else {
                max_count = max(max_count, count);
                count = 1;
            }
        }
        max_count = max(max_count, count);
        ans += max_count;
    }
    
    // Output the answer
    printf("%d", ans);
    return 0;
}