CFLAGS := -std=c99 -g -Og -Werror -Wall -Wpedantic

EXE := lib/main

OBJS := obj/bfi.o obj/stack.o obj/mem.o

$(EXE): $(OBJS) lib
	$(CC) -Iinc/ $(CFLAGS) -o $(EXE) $(OBJS)

obj/%.o: src/%.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o $@ $<

obj:
	mkdir -p obj

lib:
	mkdir -p lib

.PHONY: run
run: $(EXE)
	./$(EXE)

.PHONY: clean
clean:
	rm -rf obj/ lib/

