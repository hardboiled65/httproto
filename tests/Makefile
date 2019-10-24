OBJ = \
	main.o

CFLAGS = -I../include
LDLIBS = -L.. -lhttproto

default: $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) -o httproto-test $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
