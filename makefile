CC=mpicc
CFLAGS=-I$(IDIR) -g

IDIR=includes
ODIR=obj
SRCDIR=src

LIBS=-lgmp -lcurl

_DEPS = database.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o database.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(INCDIR)/*~
