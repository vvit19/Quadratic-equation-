TARGET = quadratic

CFlAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline\
 -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default\
  -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
   -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op\
    -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith\
	 -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits\
	  -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

COMPILE = g++ -c $^ $(CFlAGS)

.PHONY: all
all: $(TARGET)

$(TARGET): main.o solver.o tests.o utils.o cmd_arg.o io.o
	g++ $^ -o $(TARGET) $(CFlAGS)

main.o: main.cpp 
	$(COMPILE)

solver.o: solver.cpp
	$(COMPILE)

tests.o: tests.cpp
	$(COMPILE)

utils.o: utils.cpp
	$(COMPILE)

cmd_arg.o: cmd_arg.cpp
	$(COMPILE)

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o 
