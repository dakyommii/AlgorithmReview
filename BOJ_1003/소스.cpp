#include <iostream>
using namespace std;

int memo[41];


int main() {
	int n, t= 0;
	int memo[41] = {0, 1};

	for (int n = 2; n <= 40; n++)
		memo[n] = memo[n - 1] + memo[n - 2];


	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0)
			cout << "1 0" << endl;
		else
			cout << memo[n-1] << " " << memo[n] << endl;
	}

}