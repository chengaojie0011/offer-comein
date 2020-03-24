#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Solution5 {
public:
	void replaceSpace(char *str, int length) {
//		cout << str << endl;
		if (str == nullptr || length==0)
		{
			return;
		}
		int num_blank = 0;
		int org_length = 0;
		int i = 0;
		while (str[i]!='\0')
		{
			++org_length;
			if (str[i]==' ')
			{
				++num_blank;
			}
			++i;
		}
		int new_length = org_length + num_blank * 2;
		//判断会不会泄漏，边界
		if (new_length > length)
		{
			return;
		}
		int index_left = org_length;
		int index_right = new_length;

		while (index_left < index_right && index_left>=0)
		{
			if (str[index_left]==' ')
			{
				//注意写法
				str[index_right--] = '0';
				str[index_right--] = '2';
				str[index_right--] = '%';
				--index_left;
			}
			else
			{
				str[index_right] = str[index_left];
				--index_left;
				--index_right;
			}
		}

//		cout << str << endl;
		return;
	}
};


// int main()
// {
// 	//注意输入\0后要加内容，因为数组的长度是固定的，不然会内存泄漏
// 	char string[] = "we are happy!\0        ";
// 	int a[] = { 1, 2, 3, 4, 5 };
// 	int target = 7;
// 	int str_len =  sizeof(string) / sizeof(string[0]);
// 	Solution5 solution;
// 	bool output;


// 	cout << str_len << endl;
// 	solution.replaceSpace(string,str_len);


// 	system("PAUSE");
// 	return 0;
// }




