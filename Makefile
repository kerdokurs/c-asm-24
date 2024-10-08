CFLAGS := -std=c99 -g -Og -Werror -Wall -Wpedantic

EXE := lib/main
EXE_BT2C := lib/bt2c

OBJS := obj/bfi.o obj/stack.o obj/mem.o
OBJS_BT2C := obj/bt2c.o

$(EXE): $(OBJS) lib
	$(CC) -Iinc/ $(CFLAGS) -o $(EXE) $(OBJS)

$(EXE_BT2C): $(OBJS_BT2C) lib
	$(CC) -Iinc/ $(CFLAGS) -o $(EXE_BT2C) $(OBJS_BT2C)

obj/%.o: src/%.c obj
	$(CC) -c -Iinc/ $(CFLAGS) -o $@ $<

obj:
	mkdir -p obj

lib:
	mkdir -p lib

.PHONY: run
run: $(EXE)
	./$(EXE)

.PHONY: bt2c
bt2c: $(EXE_BT2C)
	./$(EXE_BT2C)

.PHONY: clean
clean:
	rm -rf obj/ lib/

