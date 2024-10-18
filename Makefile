LIB_TARGET := liboasis.a
$(shell mkdir -p build)

SOURCE_FILES := $(wildcard src/*.c)
OBJECT_FILES := $(patsubst src/%.c, build/%.o, $(SOURCE_FILES))

CC := clang
AR := ar
ARFLAGS := rcs

C_FLAGS := -Wall -Wextra -Wpedantic -Werror -std=c2x
C_DEBUG_FLAGS := -g -pg
C_RELEASE_FLAGS := -O3
C_INCLUDE_FLAGS := -Iinclude

.PHONY: all debug release clean test

all: debug

debug: C_FLAGS += $(C_DEBUG_FLAGS)
debug: $(LIB_TARGET)

release: C_FLAGS += $(C_RELEASE_FLAGS)
release: $(LIB_TARGET)

$(LIB_TARGET): $(OBJECT_FILES)
	$(AR) $(ARFLAGS) lib/$@ $^

build/%.o: src/%.c
	$(CC) $(C_FLAGS) $(C_INCLUDE_FLAGS) -c $^ -o $@

clean:
	rm -rf build test-out

test: $(LIB_TARGET)
	$(CC) $(C_FLAGS) test.c -Iinclude -Llib -lm -lSDL3 -loasis -fuse-ld=mold -o test-out
