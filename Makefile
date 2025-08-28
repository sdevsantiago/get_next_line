# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 12:31:40 by sede-san          #+#    #+#              #
#    Updated: 2025/08/28 14:37:44 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

NAME 		= get_next_line.a
BONUS_NAME	= get_next_line_bonus.a

# ************************** Compilation variables *************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Wunreachable-code
HEADERS	= -I $(INCLUDE_PATH)

ifdef BUFFER_SIZE
	CFLAGS += -DBUFFER_SIZE=$(BUFFER_SIZE)
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

MAKE += --no-print-directory

AR = ar rcs

# ****************************** Source files ******************************** #

SRC_PATH = src

SRC =									\
	$(SRC_PATH)/get_next_line.c			\
	$(SRC_PATH)/get_next_line_utils.c

BONUS_SRC =									\
	$(SRC_PATH)/get_next_line_bonus.c		\
	$(SRC_PATH)/get_next_line_utils_bonus.c

INCLUDE_PATH = ./include

# ****************************** Object files ******************************** #

OBJS_PATH = build

OBJS = $(SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)
BONUS_OBJS = $(BONUS_SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "$< compiled"

# ********************************* Rules ************************************ #

all: mandatory bonus
.PHONY: all

mandatory: $(NAME)
.PHONY: mandatory

bonus: $(BONUS_NAME)
.PHONY: bonus

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(EMOJI_CHECK) $(NAME) ready.$(RESET)"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(AR) $(BONUS_NAME) $(BONUS_OBJS)
	@echo "$(GREEN)$(EMOJI_CHECK) $(BONUS_NAME) ready.$(RESET)"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)$(EMOJI_BROOM) Object files cleaned.$(RESET)"
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@echo "$(RED)$(EMOJI_BROOM) Binaries cleaned.$(RESET)"
.PHONY: fclean

re: fclean all
.PHONY: re

# ***************************** Style variables ****************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

EMOJI_BROOM = 🧹
EMOJI_CHECK = ✅
EMOJI_CROSS = ❌
EMOJI_WRENCH = 🔧
EMOJI_BOX = 📦
