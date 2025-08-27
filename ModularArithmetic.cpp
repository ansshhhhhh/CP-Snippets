#define int long long

const int mod = 1e9 + 7;


int modpow ( int a , int b ) {
	long long res = 1;
	a %= mod ;
	while ( b > 0) {
		if ( b & 1) res = ( res * a ) % mod ;
		a = ( a * a ) % mod ;
		b >>= 1;
	}
	return res ;
}

int modinv ( int q ) {
	return modpow (q , mod - 2) ;
}

int modmul(int a, int b){
		a = a % mod;
		b = b % mod;

		return (a * b) % mod;
}

int moddiv(int a, int b){
		return modmul(a, modinv(b));
}

int modsub(int a, int b){
		return (a % mod - b % mod + mod) % mod;
}
