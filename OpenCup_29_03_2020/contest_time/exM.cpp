#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "cmath"

using namespace std;

struct tower
{
	long long L;
	long long R;
	long long D;
};

struct enemy
{
	long long H;
	long long X;
};

vector<long long> t(4 * pow(10, 5) + 1, 0);

void update(long long v, long long tl, long long tr, long long l, long long r, long long add) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] += add;
	else {
		long long tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), add);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
	}
}

long long get(long long v, long long tl, long long tr, long long pos) {
	if (tl == tr)
		return t[v];
	long long tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] + get(v * 2, tl, tm, pos);
	else
		return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}


int main() {
	long long N;
	cin >> N;

	long long M;
	cin >> M;
	long long L, R, D;
	for (long long i = 0; i < M; ++i) {
		cin >> L >> R >> D;
		update(1, 0, N - 1, L - 1, R - 1, D);
	}

	vector<long long> damage(N, 0);
	damage[N - 1] = get(1, 0, N - 1, N - 1);
	for (long long i = N - 2; i >= 0; --i) {
		damage[i] = damage[i + 1] + get(1, 0, N - 1, i);
	}

	long long K;
	cin >> K;
	long long monsterMiss = K;
	long long H, X;
	for (long long i = 0; i < K; ++i) {
		cin >> H >> X;
		if (H - damage[X - 1] <= 0) {
			--monsterMiss;
		}
	}

	cout << monsterMiss << endl;

	return 0;
}