# -*- coding:utf-8 -*-


def division_remainder(dividend, divisor):
	return int(dividend/divisor), dividend%divisor


def to_binary_classic(number):
	binary = ''
	n, r = (number, 0)

	if number == 0:
		return '0'
	elif number < 0:
		n, r = (-number, 0)
	
	while n > 0:
		n, r = division_remainder(n, 2)
		binary = str(r) + binary
	return binary


def input_type(msg, type=int):
	try:
		return type(input(msg))
	except Exception as e:
		print("Error type incorrect, expected: ", type)
		return input_type(msg, type)


def main():
	num = input_type('Enter number to convert: ')

	print(to_binary_classic(num))

if __name__ == '__main__':
	main()