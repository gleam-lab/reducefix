int x = a[i] / 5;
ans += x * 3;
a[i] -= x * 5;
while (a[i] > 0)
{
    ans++;
    if (a[i] % 3 == 0)
    {
        a[i] -= 3;
    }
    else
    {
        a[i]--;
    }
}