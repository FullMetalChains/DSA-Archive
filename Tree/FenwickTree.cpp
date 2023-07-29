#include <bits/stdc++.h>
#define ll long long

using namespace std;



class FenwickTree{
public:
	ll n;
	vector<ll>bit1, bit2;
	FenwickTree(ll z){
		n = z;
		bit1.resize(z);
		bit2.resize(z);
	}

	ll getsum(vector<ll>&b, ll i){
		ll sum = 0;
		while(i > 0){
			sum+=b[i];
			i-=(i&(-i));
		}
		return sum;
	}

	void update(vector<ll>&b, ll i, ll val){
		while(i < n){
			b[i]+=val;
			i+=(i&(-i));
		}
	}

	ll sum(ll x){
		return (getsum(bit1,x)*x) - getsum(bit2, x);
	}

	void updateRange(ll val, ll l, ll r){
		update(bit1, l, val);
		update(bit1,r + 1, -val);

		update(bit2, l, val*(l - 1));
		update(bit2, r + 1, -val*r);

	}

	ll rangesum(ll l, ll r){
		return sum(r) - sum(l - 1);
	}

};