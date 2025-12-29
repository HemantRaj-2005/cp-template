#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;

ll add(ll a, ll b){
    return (a + b) % mod;
}

ll sub(ll a, ll b){
    return (a - b + mod) % mod;
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll div(ll a, ll b){
    return (a * modInverse(b)) % mod;
}

ll modInverse(ll a){
    return power(a, mod - 2);
}   