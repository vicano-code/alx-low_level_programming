#!/usr/bin/python3

def largest_palindrome():
    num_list = []
    result = 0
    num1 = 0
    num2 = 0
    z_list_reverse = []
    for i in range(999, 99, -1):
        num_list.append(i)
    for x in num_list:
        for y in num_list:
            z = x * y
            z_list = [x for x in str(z)]
            z_list_reverse = z_list[::-1]
            if z_list == z_list_reverse:
                if z > result:
                    num1 = x
                    num2 = y
                    result = z

    print("{:d} * {:d} = {:d}".format(num1, num2,result))

largest_palindrome()
