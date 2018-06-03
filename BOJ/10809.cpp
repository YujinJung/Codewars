#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
	char S[100];
	scanf("%s", S);

	const int aOffset = 97;
	int ret[26];
	memset(ret, -1, sizeof(ret));

	for (int i = 0; S[i] != '\0'; ++i) {
		if (ret[S[i] - aOffset] == -1) {
			ret[S[i] - aOffset] = i;
		}
	}

	for (int i = 0; i < 26; ++i) {
		printf("%d ", ret[i]);
	}

	return 0;
}