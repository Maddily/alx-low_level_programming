#!/usr/bin/python3

largest_palindrome = 0

def is_palindrome(n):
	"""Checks if a number is palindromic"""

	return str(n) == str(n)[::-1]

for i in range(100, 1000):
	for j in range(100, 1000):
		product = i * j
		if is_palindrome(product) and product > largest_palindrome:
			largest_palindrome = product

print("The largest palindrome is {}".format(largest_palindrome))