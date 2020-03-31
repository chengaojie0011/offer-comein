# -*- coding:utf-8 -*-
class Solution1:
    def cutRope(self, number):
        # write code here
        if number<=1:
            return 0
        elif number ==2:
            return 1
        elif number == 3:
            return 2

        products = [0,1,2,3]
        for i in range(4,number+1):
            max= 0
            for j in range(1,int(i/2)+1):
                product = products[j]*products[i-j]
                if product > max:
                    max= product

            products.append(max)

        return max


class Solution2:
    def cutRope(self, number):
        # write code here
        if number<=1:
            return 0
        elif number ==2:
            return 1
        elif number == 3:
            return 2

        threetimes = int(number/3)
        if(number%3==1):
            threetimes -=1

        twotimes = int((number - threetimes*3)/2)

        max = pow(3,threetimes)*pow(2,twotimes)
        return max

if __name__ == "__main__":
    solution1 = Solution2()
    a = solution1.cutRope(8)
    print(a)
