// with mod
int nCr(int n, int r){
    r = min(r, n - r);
    int N = 1, D = 1;
    for(int i = n; i > n - r; i--) N = modmul(N, i);
    for(int i = 1; i <= r; i++) D = modmul(D, i);
    return moddiv(N, D);
}

int fact(int n){
		int f = 1;
		for(int i = 2; i <= n; i++)
			f *= i;

		return f;
}

// with out mod
int nCr(int n, int r){
    r = min(r, n - r);
    int N = 1, D = 1;
    for(int i = n; i > n - r; i--) N *= i;
    for(int i = 1; i <= r; i++) D *= i;
    return N / D;
}

int fact(int n){
    int f = 1;
    for(int i = 2; i <= n; i++)
      f = modmul(i, f);
		return f;                                                                                                                                                                           }
