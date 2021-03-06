
unsigned long long c[65][65], m, k, i, j, l = 1, r = 1e18, t, p, s;

int main()
{
    scanf("%I64u%I64u", &m, &k);

    c[0][0] = 1;

    for (i = 1; i <= 64; i++)
        for (j = 0; j <= i; j++)
            c[i][j] = c[i - 1][j] + (j ? c[i - 1][j - 1] : 0);

    while (l < r)
    {
        t = (l + r) >> 1;
        p = 0, s = 0;
        for (i = 63; ~i && p <= k; i--)
            if (t & 1ull << i)
                s += c[i + 1][k - p] - c[i][k - p], ++p;
        if (s < m)
            l = t + 1;
        else
            r = t;
    }

    printf("%I64u\n", l);

    return 0;
}