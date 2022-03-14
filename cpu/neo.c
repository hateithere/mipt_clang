char* whatisyourname() {
	char *res = calloc(256+1, sizeof(char));
	for (int i = 0; i < 256; ++i)
		res[i] = '1';
	return res;
}
