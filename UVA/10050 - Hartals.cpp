	bitset<4000> b;
	int n, p, x, t;
	cin >> t;
	while (t--) {
		b = 0;
		cin >> n >> p;
		for (int i = 0; i < p; ++i) {
			cin >> x;
			for (int j = x; j <= n; j += x) {
				b.set(j);
			}
		}
		for (int i = 6; i <= n; i += 7) {
			b[i] = 0;
			b[i + 1] = 0;
		}
		cout << b.count() << endl;
	}
