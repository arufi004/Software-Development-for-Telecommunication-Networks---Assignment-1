all:
	gcc assignment1.c -o assignment1
clean:
	rm assignment1
run:
	gcc assignment1.c -o assignment1
	./assignment1
	rm assignment1
