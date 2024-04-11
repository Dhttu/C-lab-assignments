CC          = gcc
CFLAGS      = -ansi -pedantic -Wall
LDFLAGS     = 
PROG_NAME   = my_suffix
OBJS        = my_suffix.o
BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
BIN_DIR     = .
ZIP_NAME    = Maman11_2.zip

ifdef DEBUG
CFLAGS += -g
endif

.PHONY: clean build_env all

all: build_env $(PROG_NAME)

$(PROG_NAME): $(OBJ_DIR)/$(OBJS)
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(PROG_NAME)

build_env:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

zip: clean
	rm -f $(ZIP_NAME)
	zip -r $(ZIP_NAME) *
