union data convert(union data x) {
	int i;
	for (i = 0; i < 4; ++i) {
		uint8_t z = x.arr[i];
		x.arr[i] = x.arr[7-i];
		x.arr[7-i] = z;
	}
	return x;
}

