all: tokenizer

tokenizer: tokenizer.c history.c user_int.c
	gcc $^ -o $@

clean:
	rm -f *.o *.c~ tokenizer
