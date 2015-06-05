
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -stdlib=libc++ -std=c++11
LD_FLAGS :=

.PHONY objdir
.PHONY clean

cte: objdir $(OBJ_FILES)
  clang++ $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
  clang++ $(CC_FLAGS) -c -o $@ $<

objdir:
  mkdir obj

clean:
  rm obj/*
  rmdir obj
  rm cte


