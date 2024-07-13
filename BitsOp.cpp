bool get_bit(long long a,int i){
    return a&(1ll<<i);
}
int get_first_bit(long long n){
    return 63-__builtin_clzll(n);
}
int get_bit_count(long long a){
    return __builtin_popcountll(a);
}