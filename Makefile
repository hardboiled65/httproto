OBJ = \
	src/httproto.o

CFLAGS = -I./include
LDLIBS = -lhttp_parser

VERSION = 0.1.2
VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_PATCH = 2
SONAME = libhttproto.so.$(VERSION_MAJOR)

PREFIX ?= /usr/local

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
endif

RSYNC_EXCLUDE_LIST = \
	--exclude .git \
	--exclude .idea \
	--exclude cmake-build-debug \
	--exclude httproto.pro.user

default: $(OBJ)
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(SONAME) -o libhttproto.so.$(VERSION) $^ $(LDLIBS)
	ln -f -s libhttproto.so.$(VERSION) libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR)
	ln -f -s libhttproto.so.$(VERSION_MAJOR).$(VERSION_MINOR) libhttproto.so.$(VERSION_MAJOR)
	ln -f -s libhttproto.so.$(VERSION_MAJOR) libhttproto.so

test:
	$(MAKE) -C tests/

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) -fPIC -o $@ $<

install: $(DESTDIR)/$(PREFIX)/lib $(DESTDIR)/$(PREFIX)/include
	strip libhttproto.so.$(VERSION)
	cp -P libhttproto.so* $(DESTDIR)/$(PREFIX)/lib/
	cp -r include/httproto $(DESTDIR)/$(PREFIX)/include/

$(DESTDIR)/$(PREFIX)/lib:
	mkdir -p $(DESTDIR)/$(PREFIX)/lib

$(DESTDIR)/$(PREFIX)/include:
	mkdir -p $(DESTDIR)/$(PREFIX)/include

tar-gz:
	rsync -av --progress . httproto-$(VERSION) $(RSYNC_EXCLUDE_LIST)
	tar cvf httproto-$(VERSION).tar httproto-$(VERSION)
	rm -r httproto-$(VERSION)
	gzip httproto-$(VERSION).tar

clean:
	rm -f src/*.o
	rm -f tests/*.o
	rm -f libhttproto.so*
	rm -f httproto-$(VERSION).tar.gz
