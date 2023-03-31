CC = gcc
RM = rm
RMDIR = rmdir
MKDIR = mkdir
INCDIR = ../inc/
OUTDIR = out/
SRCDIR = src/
UNITDIR = unit_tests/
SRCS = $(wildcard $(SRCDIR)*.c)
SRCSUNIT = $(wildcard $(UNITDIR)*.c)
NOTUNIT = $(addprefix $(OUTDIR), main.o io_file.o)
CFLAGS = -std=c99 -Wall -Werror -Wextra -Wfloat-equal -pedantic -Wfloat-conversion -Wvla

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

app.exe : $(OUTDIR) $(OBJS)
	$(CC) $(OBJS) -o $@

unit_tests.exe : $(OUTDIR) $(OBJSUNIT)
	$(CC) $(OBJSUNIT) -o $@ -lcheck

$(OUTDIR)check_%.o : $(UNITDIR)check_%.c
	cd $(OUTDIR) && $(CC) $(CFLAGS) -MD ../$< -I $(INCDIR) -c ../$<

$(OUTDIR)%.o : $(SRCDIR)%.c
	cd $(OUTDIR) && $(CC) $(CFLAGS) -MD ../$< -I $(INCDIR) -c ../$<

$(OUTDIR):
	$(MKDIR) out
	
unit : unit_tests.exe
	./unit_tests.exe

func : debug
	cd func_tests && bash all_tests.sh

include $(wildcard $(OUTDIR)*.d)

check_mem_unit_tests : unit_tests.exe
check_mem_unit_tests :
	valgrind --leak-check=full --leak-resolution=med -s ./unit_tests.exe
