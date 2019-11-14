.POSIX:

OS			= $(shell uname -s)
ifeq ($(OS), Darwin)
	PREFIX	= /usr/local
else
	PREFIX	= /usr
endif
MANPREFIX	= $(PREFIX)/share/man

install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f bin/lowbat $(DESTDIR)$(PREFIX)/bin/
	chmod 755 $(DESTDIR)$(PREFIX)$/bin/lowbat
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp -f man/lowbat.1 $(DESTDIR)$(MANPREFIX)/man1/lowbat.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/lowbat
	rm -f $(DESTDIR)$(MANPREFIX)/man1/lowbat.1

.PHONY: install uninstall
