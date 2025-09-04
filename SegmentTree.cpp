struct item {
	int val;		
};

class SegmentTree {
public:
	vector<item> value;
		
	item IDENTITY_ELEMENT = {0};
	int size;

	SegmentTree(int n){
		size = n;
		value.resize(4 * n, IDENTITY_ELEMENT);
	}

	item single (int val){
		return {val};
	}

	item merge(item item1, item item2){
		return {__gcd(item1.val, item2.val)};
	}

	void build(int x, int lx, int rx, vector<int>& a) {
		if(rx - lx <= 1){
			if(lx < size) value[x] = single(a[lx]);
			return;
		}
		
		int m = (lx + rx) / 2;

		build(2 * x + 1, lx, m, a);
		build(2 * x + 2, m, rx, a);

		value[x] = merge(value[2 * x + 1], value[2 * x + 2]);
	}

	void build(vector<int>& a) {
		build(0, 0, size, a);
	}
	
	item val(int x, int l, int r, int lx, int rx){
		if(rx <= l || r <= lx) return {IDENTITY_ELEMENT};
		if(l < lx && rx < r) return value[x];
		
		if(rx - lx <= 1) return value[x];

		int m = (lx + rx) / 2;

		item s1 = val(2 * x + 1, l, r, lx, m);
		item s2 = val(2 * x + 2, l, r, m, rx);

		return merge(s1, s2);
	}

	item val(int l, int r){
		return val(0, l, r, 0, size);
	}
};

