base = base.c
direction = direction.c base.c
grid = grid.c $(direction)
state = state.c base.c
entity = entity.c state.c $(grid)
action = action.c $(entity)
display = display.c -lSDL2
maze = maze.c $(action) $(display)

DEV = -g -fsanitize=undefined -fsanitize=address
OPT = -O2 -flto
CC = clang -D$@Test -std=c11 -Wall -pedantic $(DEV) -o m

%: %.c
	$(CC) $($@)
