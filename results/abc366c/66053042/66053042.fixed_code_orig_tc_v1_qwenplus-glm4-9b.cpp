if (m.contains(x))
{
    m[x]++;
}
else
{
    m.emplace(x, 1);
    n++;
}