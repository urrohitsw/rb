INC_DIR = ./inc
OBJ_DIR = ./obj
SRC_DIR = ./src
BIN_DIR = ./bin
BIN = bst

CPP = g++
CPP_INCLUDES = -I$(INC_DIR)
CPP_FLAGS = -Wall  -g $(DEFS)

HEADER_FILES = bstree.h bsnode.h rbnode.h rbtree.h
HEADERS = $(patsubst %,$(INC_DIR)/%,$(HEADER_FILES))

OBJECT_FILES = bstree.o bsnode.o rbtree.o rbnode.o main.o
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(OBJECT_FILES))

ifeq ($(ENABLE_RANDOM_OPERATIONS), true)
DEFS += -DENABLE_RANDOM_OPERATIONS
endif

ifeq ($(ENABLE_GRAPH_OPERATIONS), true)
DEFS += -DENABLE_GRAPH_OPERATIONS
endif

#DEFS += -std=c++11

all : init $(BIN_DIR)/$(BIN)

init :
	@test -d $(OBJ_DIR) || mkdir $(OBJ_DIR) 2>/dev/null 
	@test -d $(BIN_DIR) || mkdir $(BIN_DIR) 2>/dev/null

$(BIN_DIR)/$(BIN) : $(OBJECTS)
	$(CPP) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $(CPP_INCLUDES) -c -o $@ $^

clean: 
	rm -f $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR)
	rm -f $(BIN_DIR)/$(BIN)
	rmdir $(BIN_DIR)

.PHONY: clean
