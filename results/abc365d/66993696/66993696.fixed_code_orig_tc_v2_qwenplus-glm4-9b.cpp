#include<bits/stdc++.h>
using namespace std;
char s[200011];
char c[200011];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    
    // Initial transformation based on the game rules
    for(int i = 1; i <= n; ++i)
        c[i] = (s[i] == 'R') ? 'P' : (s[i] == 'P') ? 'S' : 'R';
    
    int ans = 0;
    int sum = n;
    
    // Optimize the sequence by adjusting pairs
    for(int i = 1; i <= n; ++i)
    {
        if(i > 1 && c[i] == c[i-1])
        {
            // If two consecutive moves are the same, revert them
            c[i] = s[i];
            sum--;
            i++; // Skip the next move as it has been optimized
        }
    }
    ans = max(ans, sum);
    
    // Do not need to revert the sequence as it is already optimized
    
    printf("%d", ans);
}