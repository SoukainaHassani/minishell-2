##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for mysh2
##

SRC_DIR = src
OBJ_DIR = obj

SRC = 		$(SRC_DIR)/mysh2.c \
      		functions/functions.c \
    		functions/functions_two.c \
      		functions/functions_three.c \
      		$(SRC_DIR)/env2.c \
      		$(SRC_DIR)/builtin2.c \
      		functions/my_str_to_word_array.c \
      		$(SRC_DIR)/pipe.c \
      		$(SRC_DIR)/pipe2.c \
      		$(SRC_DIR)/if.c \
      		$(SRC_DIR)/signal.c \
      		$(SRC_DIR)/delimiters.c \
      		$(SRC_DIR)/errors.c \
      		$(SRC_DIR)/redirections.c \
      		$(SRC_DIR)/binary.c


OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

NAME = mysh

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@

$(OBJ_DIR)/%.o: functions/%.c
	gcc -c $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

# Ensure the obj directory exists before compiling
$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
