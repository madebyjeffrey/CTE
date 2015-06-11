
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -stdlib=libc++ -std=c++11
LD_FLAGS :=

cte: $(OBJ_FILES)
	clang++ $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	clang++ $(CC_FLAGS) -c -o $@ $<

obj:
	mkdir obj

clean:
	rm obj/*
	rmdir obj
	rm cte


