// Judge whether a include any substring which is a perm of b
bool JudgeInclude(const char *a, const char *b) {
 	size_t a_len = strlen(a);
 	size_t b_len = strlen(b);
 	if (a_len < b_len) return false;
	char *counter = new char[128];
 	memset(counter, 0, 128);
 	size_t match_num = 0;
 	for (size_t i = 0; i < b_len; ++i) {
 		++counter[b[i]];
 	}
 	for (size_t i = 0; i < b_len; ++i) {
 		if (counter[a[i]] >= 1) ++match_num;
 		--counter[a[i]];
 	}
 	if (match_num == b_len) {
 		printf("[%d,%d]", 0, b_len-1);
 		return true;	
 	}
 	for (size_t i = 1, j = b_len; j < a_len; ++i, ++j) {
 		if (counter[a[i-1]] >= 0) --match_num;
 		if (counter[a[j]] >= 1) ++match_num;
 		++counter[a[i-1]];
 		--counter[a[j]];
 		if (match_num == b_len) {
 			printf("[%d,%d]", i, j);
 			return true;	
 		}
 	}
 	return false;
}

int main() {
	JudgeInclude("abcd", "ba");
	return 0;
}
