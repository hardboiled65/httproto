OBJ = \
	src/httproto.o

CFLAGS = -I./include
LDLIBS = -lhttp_parser

VERSION = 0.1.0
VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_PATCH = 0
SONAME = libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR)

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
endif

default: $(OBJ)
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(SONAME) $(LDLIBS) -o libhttproto.so.$(VERSION) $^
	ln -f -s libhttproto.so.$(VERSION) libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR)
	ln -f -s libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR) libhttproto.so.$(VERSION_MAJOR)
	ln -f -s libhttproto.so.$(VERSION_MAJOR) libhttproto.so

test:
	$(MAKE) -C tests/

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) -fPIC -o $@ $<

install:
	cp -P libhttproto.so* /usr/local/lib/
	cp -r include/httproto /usr/local/include/

clean:
	rm -f src/*.o
	rm -f libhttproto.so*
