#define int long long

const int MOD = 1e9 + 7;


int modpow ( int a , int b ) {
	long long res = 1;
	a %= MOD ;
	while ( b > 0) {
		if ( b & 1) res = ( res * a ) % MOD ;
		a = ( a * a ) % MOD ;
		b > >= 1;
	}
	return res ;
}

int modinv ( int q ) {
	return modpow (q , MOD - 2) ;
}
