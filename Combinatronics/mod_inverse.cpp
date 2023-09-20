#include <iostream>
#define ll long long

ll mod = 1e9 + 7;

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%mod;
        y = y >> 1;
        x = (x * x)%mod;
    }
    return res % mod;
}

ll mod_inverse(ll x){
    return power(x, mod - 2);
}