OBJ = \
	main.o

CFLAGS = -g -I../include -Wl,-rpath=../
LDLIBS = -L.. -lhttproto

default: $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) -o httproto-test $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
