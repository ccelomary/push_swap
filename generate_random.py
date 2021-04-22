#!/usr/bin/python3.8
import random
import	sys

if __name__ == '__main__':
	length = int(sys.argv[1])
	counter = 0
	lst = []
	while counter < length:
		number = random.randint(-2 ** 31, 2 ** 31 - 1)
		if not number in lst:
			lst.append(number)
			counter += 1
	for number in lst:
		print(number, end=" ")
	print()

