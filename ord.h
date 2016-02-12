#include <iostream>
using namespace std;
int** simpleMul(int** a, int** b, int aw, int al, int bw, int bl)
{
	int** c = new int*[al];
	for (int i = 0; i < al; ++i)
		c[i] = new int[bw];
	if (aw == bl)
	{

		for (int i = 0; i<al; i++)
		{
			for (int j = 0; j<aw; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k<bw; k++)
				{
					c[i][j] = c[i][j] + a[i][k] * b[k][j];
				}
			}
		}



		for (int i = 0; i<al; i++)
		{
			for (int j = 0; j<bw; j++)
			{
				cout << "\t" << c[i][j];
			}
			cout << "\n\n";
		}
	}
	else
	{
		cout << "\n\nMultiplication is not possible";
	}


	return c;




}


int** strassenMul(int** a, int** b)
{
	int m1, m2, m3, m4, m5, m6, m7, i, j;
	int aw = 2;
	int al = 2;
	int bw = 2;
	int bl = 2;
	int** c = new int*[al];
	for (int i = 0; i < al; ++i)
		c[i] = new int[bw];
	m1 = (a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
	m2 = (a[1][0] + a[1][1])*b[0][0];
	m3 = a[0][0] * (b[0][1] - b[1][1]);
	m4 = a[1][1] * (b[1][0] - b[0][0]);
	m5 = (a[0][0] + a[0][1])*b[1][1];
	m6 = (a[1][0] - a[0][0])*(b[0][0] + b[0][1]);
	m7 = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);
	c[0][0] = m1 + m4 - m5 + m7;
	c[0][1] = m3 + m5;
	c[1][0] = m2 + m4;
	c[1][1] = m1 - m2 + m3 + m6;

	for (i = 0; i<2; i++)
	{
		for (j = 0; j<2; j++)
		{

			cout << c[i][j];
		}
		cout << "\n";
	}


	return c;


}
