#include<vector>
// using namespace std;

class Solution {
public:
	::std::vector<::std::vector<int>> generateMatrix(int n) {
		::std::vector<::std::vector<int>> v(n, ::std::vector<int>(n, -1));
		if (n == 1) {
			v[0][0] = 1;
			return v;
		}		
		int count = n * n;
		int temp = count + 1;
		for (int i = -1, j = -1; count > 0; ) {
			if(j < n && v[++i][++j] == -1)
				while (j < n && v[i][j] == -1)
					v[i][j++] = temp - count--;
			if (i < n && v[++i][--j] == -1)
				while (i < n && v[i][j] == -1)
					v[i++][j] = temp - count--;
			if (j > -1 && v[--i][--j] == -1)
				while (j > -1 && v[i][j] == -1)
					v[i][j--] = temp - count--;
			if (i > -1 && v[--i][++j] == -1)
				while (i > -1 && v[i][j] == -1)
					v[i--][j] = temp - count--;
		}		
		return v;
	}
};