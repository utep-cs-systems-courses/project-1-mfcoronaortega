all: tokenizer

tokenizer:tokenizer.c history.c simple_ui.c
	gcc $^ -o $@
clean:
	rm -f *.o *.c~ tokenizer
