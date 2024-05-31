#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	char a;
	cin >> n >> a;
	int m = sqrt((n+1)/2);
	for (int i=0; i<m; i++) {
		int p = m-i;
		for (int j=0; j<=i-1; j++) cout << " ";
		for (int j=0; j<=2*(p-1); j++) cout << a;
		cout << endl;
	}
	for (int i=1; i<m; i++) {
		int p = m-i;
		for (int j=0; j<=p-2; j++) cout << " ";
		for (int j=0; j<=2*i; j++) cout << a;
		cout << endl;
	}
	cout << n - 2*m*m+1;
	return 0;
}
