#include <iostream>

int cellvalue(int d[5][5], int f[3][3], int i, int j)
{
	int val;
	for(int x = 0, di = i; x < 3; x++, di++)
	{
		for(int y = 0, dj = j; y < 3; y++, dj++)
		{
			val += d[di][dj] * f[x][y];
		}
	}
	return val;
}

void convolve(int d[5][5], int f[3][3], int res[3][3])
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			res[i][j] = cellvalue(d, f, i, j);
}

int main()
{
	int d[5][5] = {{1,2,3,4,5},
				   {0,1,2,3,4},
				   {1,0,5,4,2},
				   {3,2,1,5,3},
				   {1,2,1,1,0}};

	int f[3][3] = {{1,0,1},
				   {1,0,1},
				   {1,0,1}};

	int res[3][3] = {0};

	convolve(d, f, res);

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			std::cout << res[i][j] << " ";
		std::cout << std::endl;
	}
		
	return 0;
}
