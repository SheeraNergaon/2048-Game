CC = cl
OBJS = game.obj main.obj board.obj menu.obj
EXEC = prog1.exe
DEBUG = /Zi
CFLAGS = /W4 $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) /Fe$(EXEC)

game.obj: game.c game.h
	$(CC) $(CFLAGS) /c game.c /Fo$@

main.obj: main.c game.h
	$(CC) $(CFLAGS) /c main.c /Fo$@

board.obj: board.c board.h
	$(CC) $(CFLAGS) /c board.c /Fo$@
menu.obj: menu.c menu.h
	$(CC) $(CFLAGS) /c menu.c /Fo$@

clean:
	del $(OBJS) $(EXEC)
