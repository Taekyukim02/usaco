void add(line l) {
	while(L.size() >= 2 && bad(L[L.size()-2], L.back(), l))
		L.pop_back();
	L.push_back(l);
}

// check if l1 ^ l2 < l1 ^ l3  <==>  bad
// only works if slopes are all positive
bool bad(line l1, line l2, line l3) {
	return (l2.b-l1.b)*(l1.m-l3.m) <= (l3.b-l1.b)*(l1.m-l3.m);
}

// binary search for line
double query(double x) {
	int lo = 0, hi = L.size()-1;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		if(L[mid+1](x) < L[mid](x))
			lo = mid+1;
		else
			hi = mid;
	}

	return L[lo](x);
}
