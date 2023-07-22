#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <string> 
#include <unordered_map> 
using namespace std;




int main() {
	int n;
	cin >> n;
	int p, q;
	long long int m, y;
	double del, p_d;
	for (int i = 0; i < n; i++) {
		scanf("%d/%d xor %llx", &p, &q, &m);
		p_d = (double)p;
		del = p_d / q;

		for (int k = 0; k < 8; k++) {
			((unsigned char*)(&y))[k] = ((unsigned char*)(&del))[k];
		}
		y = y ^ m;
		for (int k = 0; k < 8; k++) {
			((unsigned char*)(&del))[k] = ((unsigned char*)(&y))[k];
		}
		printf(" %0.15g\n ", del);
	}
}