vector<int> normalSieve(int n)
{
    vector<int>v={2};
    bool prime[n / 2];
    memset(prime, false, sizeof(prime));
    for (int i = 3; i * i < n; i += 2) {
        if (prime[i / 2] == false)
            for (int j = i * i; j < n; j += i * 2)
                prime[j / 2] = true;
    }
    for (int i = 3; i < n; i += 2)
        if (prime[i / 2] == false)
            v.push_back(i);
    return v;
}