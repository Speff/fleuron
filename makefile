TARGET = fleuron

IDIR   = include
LDIR   = 
CC     = gcc
#CFLAGS = -g -Wall -Wno-missing-braces -Wno-unused-variable -I$(IDIR)
CFLAGS =  -O2 -s  -I$(IDIR)

ODIR   = obj

LIBS   = 

_DEPS  = 
DEPS   = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ   = fleuron.o
OBJ    = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	@IF NOT EXIST "obj\\" mkdir obj
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	ar rcs lib$(TARGET).a $^

.PHONY: clean

clean:
	DEL /Q /F /S "$(ODIR)\*.o"
	DEL /Q /F /S "$(TARGET).exe"
	DEL /Q /F /S "lib$(TARGET).a"

