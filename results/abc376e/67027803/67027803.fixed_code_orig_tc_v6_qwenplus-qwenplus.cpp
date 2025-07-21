if (k == 1) {
  ll ans = inf;
  for (int i=0; i<n; i++) {
    ans = min(ans, ab[i].first * ab[i].second);
    cout << ans << '\n';
    return;
  }
}