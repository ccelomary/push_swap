#!/Users/mel-omar/goinfre/.brew/opt/python@3.8/bin/python3.8

if __name__ == "__main__":
	counter = 0
	while True:
		try:
			input()
		except EOFError:
			break
		counter += 1
	print(counter)
