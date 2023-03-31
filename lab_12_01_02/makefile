CC = gcc
RM = rm
RMDIR = rmdir
MKDIR = mkdir
INCDIR = ../inc/
LIBDIR = lib/
OUTDIR = out/
SRCDIR = src/
UNITDIR = unit_tests/
SRCS = $(wildcard $(SRCDIR)*.c)
SRCSUNIT = $(wildcard $(UNITDIR)*.c)
NOTUNIT = $(addprefix $(OUTDIR), main.o io_file.o)
CFLAGS = -std=c99 -Wall -Werror -Wextra -Wfloat-equal -pedantic -Wfloat-conversion -Wvla
LIBSRCS = $(wildcard $(LIBDIR)*.c)
DFLAGS = $(CFLAGS)
CDIR = $(SRCDIR)

.PHONY : debug release unit func clean check_mem_unit_tests OUTDIR
release : CFLAGS += -DNDEBUG -g0
release : app.exe

debug : CFLAGS += -g3
debug : app.exe

clean :
	$(RM) -f $(OUTDIR)*.* *.exe
	$(RMDIR) $(OUTDIR)

OBJS = $(addprefix $(OUTDIR),$(addsuffix .o,$(notdir $(basename $(SRCS)))))
OBJSUNIT = $(addprefix $(OUTDIR),$(addsuffix .o,$(notdir $(basename $(SRCSUNIT))))) $(filter-out $(NOTUNIT), $(OBJS))
OBJSLIB = $(addprefix $(OUTDIR),$(addsuffix .o,$(notdir $(basename $(LIBSRCS)))))

ifeq (lib.so, $(firstword $(MAKECMDGOALS)))
	CFLAGS := $(CFLAGS) -fPIC
	CDIR = $(LIBDIR)
else ifeq (unit_tests.so, $(firstword $(MAKECMDGOALS)))
	CFLAGS := $(CFLAGS) -fPIC
endif

app.exe : $(OUTDIR) $(OBJS)
	$(CC) $(OBJS) -o $@ $(OUTDIR)lib.so

unit_tests.exe : $(OUTDIR) $(OBJSUNIT)
	$(CC) $(OBJSUNIT) -o $@ -lcheck

lib.so : $(OUTDIR) $(OBJSLIB)
	$(CC) -shared $(DFLAGS) -o $(OUTDIR)lib.so $(OBJSLIB)

print :
	echo $(CDIR)

$(OUTDIR)check_%.o : $(UNITDIR)check_%.c
	cd $(OUTDIR) && $(CC) $(CFLAGS) -MD ../$< -I $(INCDIR) -c ../$<

$(OUTDIR)%.o : $(CDIR)%.c
	cd $(OUTDIR) && $(CC) $(CFLAGS) -MD ../$< -I $(INCDIR) -c ../$<

$(OUTDIR):
	$(MKDIR) out
	
unit : unit_tests.exe
	./unit_tests.exe

func :
	bash all_tests.sh

include $(wildcard $(OUTDIR)*.d)

check_mem_unit_tests : unit_tests.exe
check_mem_unit_tests :
	valgrind --leak-check=full --leak-resolution=med -s ./unit_tests.exe
