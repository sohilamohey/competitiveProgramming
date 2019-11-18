#define ll long long

ll power(ll x, ll y, int mod) {
	if (y == 0) return 1;
	if (y == 1) return x % mod;
	ll r = power(x, y >> 1, mod);
	return (((r * r) % mod) * power(x, y & 1, mod)) % mod;
}

// (a / b) % mod = (a% mod) * (b ^ (mod - 2))%mod
// Modular inverse of the given number modulo mod
// return z = (1/b) % mod // mod must be Prime
ll modInverse(ll b, ll mod) {
	return power(b, mod - 2, mod);
}

// Calulate Modular inverse
ll modInv(ll a, ll m) {
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1)
		return 0;
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
		x1 += m0;
	return x1;
}

const int N = 1e5 + 100;
const int mod = 1e9 + 7;
ll fact[N];
ll inv[N];//mod inverse for i
ll invfact[N];//mod inverse for i!
void factInverse() {
	fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
	for (long long i = 2; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
		invfact[i] = (inv[i] * invfact[i - 1] % mod);
	}
}