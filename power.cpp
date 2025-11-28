long long power(long long x, int y)
{
    long long res = 1;
    long long mod=1e9+7;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res % mod;
}
