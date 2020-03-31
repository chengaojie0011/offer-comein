# -*- coding:utf-8 -*-
class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        if len(numbers) ==None:
            return None

        num = numbers[0]
        time = 1
        for i in numbers[1:]:
            if num ==i:
                time +=1
            else:
                time -=1
            if time == 0:
                num = i
                time = 1
        time2 = 0
        for j in numbers:
            if j == num:
                time2 +=1
        # print(time2)
        if time2>len(numbers)/2:
            return num
        else:
            return 0


if __name__ == '__main__':
    str = "abc"
    # x_list = str.split('')
    # x_list = list(str)
    # print(x_list)
    # x_str = ''.join(x_list)
    # print(x_str)
    l = [1, 2, 3, 2, 2, 2, 5, 4, 2]
    solution1 = Solution()
    a = solution1.MoreThanHalfNum_Solution(l)
    print(a)