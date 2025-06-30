# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 12:31:40 by sede-san          #+#    #+#              #
#    Updated: 2025/06/30 12:44:25 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

# Executable file
NAME = get_next_line

# ************************** Compilation variables *************************** #

# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

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

all: $(OBJ)
	$(AR) $(NAME).a $(OBJ)

bonus: $(BONUS_OBJ)
	$(AR) $(NAME).a $(BONUS_OBJ)
clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME).a

# *********************************** Phony ********************************** #

.PHONY: all bonus clean fclean
