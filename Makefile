NAME = sle

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++17
CXXFLAGS += $(shell pkg-config --cflags gtkmm-4.0)

LDLIBS = $(shell pkg-config --libs gtkmm-4.0) -lcurl

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	src/main.cpp \
	src/janela.cpp \
	src/menu.cpp \
	src/read_file.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INCLUDES = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
