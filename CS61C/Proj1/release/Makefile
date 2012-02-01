TARGET      := game
CC		    := gcc
OBJDIR      := obj
SRCFILES    := $(wildcard *.c)
HEADERS     := $(wildcard *.h)
OBJFILES    := $(SRCFILES:%.c=$(OBJDIR)/%.o)
CFLAGS      := -std=c99 -g -Wall

run: $(TARGET)
	./$(TARGET) 

test: $(TARGET)
	./$(TARGET) testworld.lvl

debug: $(TARGET)
	gdb $(TARGET)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

print:
	@echo "SRCFILES: " $(SRCFILES)
	@echo "OBJFILES: " $(OBJFILES)
	@echo "CFLAGS:   " $(CFLAGS)

edit:
	vim -p *.h *.c

$(TARGET): $(OBJFILES)
	$(CC) $+ $(CFLAGS) -o $(TARGET)

$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

release:
	cd .. && ./make_release && cd ./release && make

loc:
	wc *.c *.h
