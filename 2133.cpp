// 2133�� Ÿ��ä���

#include <iostream>

int p[31] = { 0 };
int dp[31] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	p[0] = 1;
	p[2] = 3;
	dp[0] = 1;

	// �ڱ� �ڽ����� �����ϰ� ���� �� �ִ°�,
	// ���ʳ��� 2x1, ����� ��ġ�� 1x2�� ���̰�, ���Ʒ��� 1x2�� ��ħ
	for (int i = 4; i <= N; i += 2)
		p[i] = 2;

	//f(N) = f(N-2)*f(2) +  f(N-4)*f(4) + f(N-6)*f(6) ...
	//N�� Ȧ���� ���� �Ұ�, 0���� �ʱ�ȭ. 2�� ����.

	for (int i = 2; i <= N; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			dp[i] += dp[i - j] * p[j];
		}
	}

	printf("%d", dp[N]);


	return 0;
}