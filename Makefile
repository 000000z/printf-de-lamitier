# Specify the name of your executable/library
NAME	= libftprintf.a

# Specify the directories where your source files and header files are located
SRC_DIR	= src
INC_DIR	= includes

# List all your source files
SRC		= $(wildcard $(SRC_DIR)/*.c)

# Convert the list of source files into a list of object files
OBJ		= $(patsubst $(SRC_DIR)/%.c,%.o,$(SRC))

# Specify the compiler and the flags to use
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INC_DIR)

# Specify the archiver and the flags to use
AR      = ar rc
RANLIB  = ranlib

# Specify the name of your main program (if you have one)
MAIN	= main

# Specify the name of your test program (if you have one)
TEST	= test

# Default rule: build the library
all: ${NAME}

# Rule to build the library
${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	${RANLIB} ${NAME}

# Rule to build object files from source files
%.o: $(SRC_DIR)/%.c
	${CC} ${CFLAGS} -c $< -o $@

# Rule to build the main program (if you have one)
${MAIN}: ${NAME} ${MAIN}.c
	${CC} ${CFLAGS} ${MAIN}.c ${NAME} -o ${MAIN}

# Rule to build the test program (if you have one)
${TEST}: ${NAME} ${TEST}.c
	${CC} ${CFLAGS} ${TEST}.c ${NAME} -o ${TEST}

# Rule to clean up object files and the executable/library
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ${NAME} ${MAIN} ${TEST}

# Rule to rebuild the project from scratch
re: fclean all

# Specify that the rules "all", "clean", "fclean", "re" do not correspond to files
.PHONY: all clean fclean re
