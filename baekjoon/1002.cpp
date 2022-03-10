#include <stdio.h>
#include <math.h>

int main()
{
	int x1, y1, r1, x2, y2, r2, t,ans;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double s = r1 > r2 ? r1 - r2 : r2 - r1;
		double D = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); //(x1, y1)과 (x2,y2)의 거리
		

		if (r1 == r2 && D == 0) ans = -1; // 교점이 무한대인 경우
		else if (D == r1 + r2 || D == s) ans = 1; // 교점이 1개인 경우
		else if (r1 > D + r2 || r2 > D + r1 || D > r1 + r2) ans = 0; // 교점이 0개인 경우
		else if (D < r1 + r2 && s < D) ans = 2; // 교점이 2개인 경우
        
        printf("%d\n", ans);
	}

}

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int x1, y1, r1, x2, y2, r2, t;
	double D, s;

	cin >> t;

	while (t--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		s = r1 > r2 ? r1 - r2 : r2 - r1;
		D = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		

		if (r1 == r2 && D == 0) cout << "-1\n"; // 교점이 무한대인 경우
		else if (D == r1 + r2 || D == s) cout << "1\n"; // 교점이 1개인 경우
		else if (r1 > D + r2 || r2 > D + r1 || D > r1 + r2) cout << "0\n";
		else if (D < r1 + r2 && s < D) cout << "2\n";
	}

}
