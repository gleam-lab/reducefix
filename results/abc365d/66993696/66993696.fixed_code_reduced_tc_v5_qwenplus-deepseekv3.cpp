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
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=s[i]) sum++;
    }
    for(int i=2;i<=n;i++)
    {
        if(c[i]==c[i-1])
        {
            if(c[i]!=s[i] && c[i-1]!=s[i-1])
            {
                if(s[i]=='P') c[i]='R';
                else if(s[i]=='R') c[i]='S';
                else c[i]='P';
                if(c[i]!=s[i]) sum++;
            }
        }
    }
    printf("%d",sum);
}