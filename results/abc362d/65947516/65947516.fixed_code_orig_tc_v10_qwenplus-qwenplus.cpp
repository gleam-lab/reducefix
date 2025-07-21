if(dis[i.first] > dis[now.id] + i.second + a[now.id])
{
    dis[i.first] = dis[now.id] + i.second + a[now.id];
    ...
}