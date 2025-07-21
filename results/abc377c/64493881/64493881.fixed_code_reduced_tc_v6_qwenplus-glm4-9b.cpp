if ((1 <= a2 && a2 <= N) && (1 <= b1 && b1 <= N)) {
    ans.emplace(a2, b1);
} else if (a2 > N) ans.emplace(a2, b1 - 1);
else if (b1 > N) ans.emplace(a2 - 1, b1);