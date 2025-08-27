# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 12:31:40 by sede-san          #+#    #+#              #
#    Updated: 2025/08/27 02:32:31 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

# Executable file
NAME = get_next_line
BONUS_NAME = get_next_line_bonus

# ************************** Compilation variables *************************** #

# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

ifdef BUFFER_SIZE
	CFLAGS += -DBUFFER_SIZE=$(BUFFER_SIZE)
endif

# Make command with no-print-directory flag
MAKE += --no-print-directory

AR = ar rcs

# ****************************** Source files ******************************** #

# Source files path
SRC_PATH = src

# Source files
SRC = \
	get_next_line.c \
	get_next_line_utils.c

# Bonus files
BONUS_SRC = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

# ****************************** Object files ******************************** #

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************* Rules ************************************ #

all: mandatory bonus
.PHONY: all

mandatory: $(NAME).a
.PHONY: mandatory

$(NAME).a: $(OBJ)
	$(AR) $(NAME).a $(OBJ)

bonus: $(NAME)_bonus.a
.PHONY: bonus

$(NAME)_bonus.a: $(BONUS_OBJ)
	$(AR) $(NAME)_bonus.a $(BONUS_OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
.PHONY: clean

fclean: clean
	rm -f $(NAME).a
	rm -f $(NAME)_bonus.a
.PHONY: fclean

re: fclean all
.PHONY: re
