#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Solution4 {
public:
	bool Find(int target, vector<vector<int>> array) {
		int row = 0;
		int column = array.size() - 1;
		while (row >= 0 && row < array[0].size() && column >= 0 && column < array.size())
		{
			if (target == array[row][column])
			{
//				cout << "row is" << row << endl;
//				cout << "column is" << column << endl;
				return true;
			}
			else if (target < array[row][column])
			{
				--column;
			}
			else
			{
				++row;
			}

		}
		return false;
	}
};

// int main()
// {
// 	vector<vector<int>> data = { { 1, 2, 8, 9 }, { 2, 4, 9, 12}, { 4, 7, 10, 13 }, { 6, 8, 11, 15 }};
// 	int target = 7;
// 	Solution4 solution;
// 	bool output;
// //	cout << data[2][1] << endl;
// 	output = solution.Find(7,data);
// //	cout << output << endl;


// 	system("PAUSE");
// 	return 0;
// }




