#include<bits/stdc++.h>
using namespace std;
char s[200011];
char c[200011];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='P') c[i]='S';
        else if(s[i]=='R') c[i]='P';
        else c[i]='R';
    }
    int sum = n;
    for(int i=2;i<=n;i++)
    {
        if(c[i]==c[i-1])
        {
            if(i < n && s[i+1] != c[i]) {
                if(s[i+1]=='P') c[i]='S';
                else if(s[i+1]=='R') c[i]='P';
                else c[i]='R';
            } else {
                c[i] = s[i];
            }
            sum--;
        }
    }
    int ans = sum;
    sum = n;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='P') c[i]='S';
        else if(s[i]=='R') c[i]='P';
        else c[i]='R';
    }
    if(n > 1 && c[1] == c[2]) {
        c[1] = s[1];
        sum--;
        for(int i=3;i<=n;i++)
        {
            if(c[i]==c[i-1])
            {
                if(i < n && s[i+1] != c[i]) {
                    if(s[i+1]=='P') c[i]='S';
                    else if(s[i+1]=='R') c[i]='P';
                    else c[i]='R';
                } else {
                    c[i] = s[i];
                }
                sum--;
            }
        }
    }
    ans = max(ans, sum);
    printf("%d",ans);
}