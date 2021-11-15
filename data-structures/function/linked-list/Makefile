PREFIX=/usr/local/include/ctools
LIBRARY=linked-list.h

install: $(PREFIX)/$(LIBRARY)

uninstall:
	rm -f $(PREFIX)/$(LIBRARY)

$(PREFIX)/$(LIBRARY): $(LIBRARY)
	mkdir -p $(PREFIX)
	cp $(LIBRARY) $(PREFIX)
