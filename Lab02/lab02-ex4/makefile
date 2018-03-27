CC=gcc
CFLAGS=-Wall
LIBS=-ansi -lm
DEPS=sum.h

ODIR=obj

_OBJ=main.o sum.o
OBJ=$(pathsubset %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~