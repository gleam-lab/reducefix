#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], t[1000005], an, w[400005];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
        a[i+n] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        w[i] = (w[i-1] + a[i]) % m;
    }
    for (int i = 1; i <= n; i++)
    {
        t[w[i]]++;
    }
    an = t[0]; // Start with the count of the first prefix sum
    for (int i = 1; i <= n; i++)
    {
        an += t[w[i]]; // Add the count of the current prefix sum
        t[w[i-n]]--; // Subtract the count of the previous prefix sum if it's within bounds
        t[w[i]]++; // Increment the count of the current prefix sum
    }
    cout << an;
    return 0;
}