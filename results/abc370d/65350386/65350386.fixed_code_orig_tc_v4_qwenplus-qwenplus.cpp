auto it = set.lower_bound(pos);
if (it != set.begin()) {
    --it;
    // Found wall before pos
}