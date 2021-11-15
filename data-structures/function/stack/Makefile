PREFIX=/usr/local/include/ctools
LIBRARY=stack.h

install: $(PREFIX)/$(LIBRARY)

uninstall:
	rm -f $(PREFIX)/$(LIBRARY)

$(PREFIX)/$(LIBRARY): $(LIBRARY)
	mkdir -p $(PREFIX)
	cp $(LIBRARY) $(PREFIX)
