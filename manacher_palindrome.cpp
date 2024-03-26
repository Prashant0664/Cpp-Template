vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

string longestPalindrome(string s) {
    int n = s.length();
    vector<char> newStr(2*n+1);
    int i = 0;
    newStr[i++] = '#';
    for(char c : s){
        newStr[i++] = c;
        newStr[i++] = '#';
    }

    vector<int> p(2*n+1);
    int center = 0, right = 0;

    int longestLength = 0, longestCenter = 0;

    for(i = 0; i < newStr.size(); i++){

        int mirror = 2*center - i;

        if(right > i){
            p[i] = min(p[mirror], right - i);
        }

        int a = i + (p[i] + 1);
        int b = i - (p[i] + 1);

        while(b >= 0 && a < newStr.size() && newStr[a] == newStr[b]){
            b--;
            a++;
            p[i]++;
        }

        if(p[i] >= longestLength){
            longestCenter = i;
            longestLength = p[i];
        }

        if(i + p[i] > right){
            center = i;
            right = i + p[i];
        }
    }

    string st(newStr.begin(), newStr.end());
    st = st.substr(longestCenter - longestLength, 2*longestLength);
    st.erase(remove(st.begin(), st.end(), '#'), st.end());
    return st;
}