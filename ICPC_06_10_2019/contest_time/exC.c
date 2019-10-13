#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
int main() {
	uint32_t N, res = 0;

	scanf("%"SCNu32, &N);

	uint_fast8_t *vec = (uint_fast8_t*) malloc(sizeof(uint_fast8_t) * N);
	memset(vec, 0, N * sizeof(uint_fast8_t));

	uint_fast32_t n;
    

    for (uint32_t i = 0; i < N; ++i) {
    	scanf("%"SCNu32, &n);
    	if ((n <= (uint_fast32_t) N) && !vec[n - 1]) {
        	vec[n - 1] = 1;
    		++res;
    	}
    }

	printf("%"PRIu32 "\n", res);
	free(vec);
	return 0;
}
