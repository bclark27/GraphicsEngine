# tool macros
CC := gcc# FILL: the compiler
CCFLAGS := # FILL: compile flags
DBGFLAGS := -Wall -Werror -g
CCOBJFLAGS := $(CCFLAGS) -c
LIBS := -L./lib/ -lcomm -lusb-1.0 -lGL -lglfw -lGLEW -lm

# path macros
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src
DBG_PATH := debug
SHADERS_SUB_DIR := shaders

# compile macros
TARGET_NAME := ge# FILL: target name
ifeq ($(OS),Windows_NT)
	TARGET_NAME := $(addsuffix .exe,$(TARGET_NAME))
endif
TARGET := $(BIN_PATH)/$(TARGET_NAME)
TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(shell find $(SRC_PATH) -type f -name "*.c")     #$(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))     #$(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_DEBUG := $(addprefix $(DBG_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ) \
                  $(OBJ_DEBUG)
CLEAN_LIST := $(TARGET) \
			  $(TARGET_DEBUG) \
			  $(DISTCLEAN_LIST) \
				$(BIN_PATH)/$(SHADERS_SUB_DIR)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $(OBJ) $(LIBS)
	@mkdir -p $(dir $@)
	@echo "cp shaders"
	@cp -r $(SRC_PATH)/$(SHADERS_SUB_DIR) $(BIN_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	@mkdir -p $(dir $@)
	$(CC) $(CCOBJFLAGS) -o $@ $<

$(DBG_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(CCOBJFLAGS) $(DBGFLAGS) -o $@ $<

$(TARGET_DEBUG): $(OBJ_DEBUG)
	$(CC) $(CCFLAGS) $(DBGFLAGS) $(OBJ_DEBUG) -o $@  $(LIBS)

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH) $(DBG_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -rf $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)
