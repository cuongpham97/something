#include "stdafx.h"

#define MAXPOINT 100
#define MAXCTRL 3

POINT Ctrl[6] = { { 100, 100 }, {300, 100}, {300, 300}};

int __fastcall combin(int k, int n)
{
	int result = 1;
	for (int i = n; i > k; --i) result *= i;
	for (int i = 2; i <= n - k; ++i) result /= i;
	return result;
}

float __fastcall blendFunc(float t, int k, int n) //n=nCtrl
{
	return pow(t, k)*pow(1 - t, n - k)*combin(k, n);
}

POINT* __fastcall Bezier(POINT* Ctrl, int nCtrl = MAXCTRL, int nPoint = MAXPOINT)
{
	POINT* result = new POINT[nPoint];
	memset(result, 0, sizeof(POINT) * nPoint);
	for (int n = 0; n < nPoint; ++n) {	
		float t = static_cast<float>(n)/(nPoint - 1) ;

		for (int k = 0; k < nCtrl; ++k) {
			float B = blendFunc(t, k, nCtrl-1);
			result[n].x += Ctrl[k].x*B;
			result[n].y += Ctrl[k].y*B;
		}
	}
	return result;
}

int  main(int argc, char* argv[])
{
	using namespace std;
	initwindow(1000, 600);
	clock_t begin = clock();
	POINT* BezCuves = Bezier(Ctrl);

	for (size_t i = 1; i < MAXCTRL; i++)
	{
		line(Ctrl[i - 1].x, Ctrl[i - 1].y, Ctrl[i].x, Ctrl[i].y);
	}

	for (size_t i = 1; i < MAXPOINT; i++)
	{
		putpixel(BezCuves[i].x, BezCuves[i].y, RED);;
	}
	clock_t end = clock();
	cout << difftime(end, begin);
	system("pause");
	closegraph();
	return 0;
}
