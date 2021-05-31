OBJ = \
	main.o

CFLAGS = -g -I../include -Wl,-rpath=../
LDLIBS = -L.. -lhttproto

default: $(OBJ)
	$(CC) $(CFLAGS) -o httproto-test $^ $(LDLIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
