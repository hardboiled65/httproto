OBJ = \
	src/httproto.o

CFLAGS = -I./include
LDLIBS = -lhttp_parser

VERSION = 0.1.0
VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_PATCH = 0
SONAME = libprimer.so.$(VERSION)

default: $(OBJ)
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(SONAME) -o libhttproto.so.$(VERSION) $^
	ln -f -s libhttproto.so.$(VERSION) libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR)
	ln -f -s libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR) libhttproto.so.$(VERSION_MAJOR)
	ln -f -s libhttproto.so.$(VERSION_MAJOR) libhttproto.so

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) -fPIC -o $@ $<

clean:
	rm -f src/*.o
	rm -f libhttproto.so*
