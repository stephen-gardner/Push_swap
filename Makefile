#!/usr/bin/make -f

################################################################################
# SETTINGS                                                                     #
################################################################################

PUSH_SWAP = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I inc -I libft/inc
LIBFT = libft/libft.a
SRC_DIR = src
PS_SRC = \
	check\
	push_swap\
	rotate\
	sort
SHARED_SRC = \
	list_stack\
	load\
	ops\
	util
OBJ_DIR = $(SRC_DIR)/obj
SHARED_OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SHARED_SRC))
PS_OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(PS_SRC))

################################################################################
# COLORS                                                                       #
################################################################################

NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m

################################################################################
# RULES                                                                        #
################################################################################

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(LIBFT) $(SHARED_OBJ) $(PS_OBJ)
	@printf "$(YELLOW)%-35s$(NC)" "Building $@... "
	@$(CC) $(CFLAGS) $(LIBFT) $(SHARED_OBJ) $(PS_OBJ) -o $@
	@echo "$(GREEN)DONE$(NC)"

$(CHECKER): $(LIBFT) $(SHARED_OBJ) $(OBJ_DIR)/checker.o
	@printf "$(YELLOW)%-35s$(NC)" "Building $@... "
	@$(CC) $(CFLAGS) $(LIBFT) $(SHARED_OBJ) $(OBJ_DIR)/checker.o -o $@
	@echo "$(GREEN)DONE$(NC)"

$(LIBFT):
	@printf "$(YELLOW)%-35s$(NC)" "Building $@... "
	@make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo " > Compiling $<..."
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean
	@echo "$(RED)Object files removed$(NC)"

fclean: clean
	@make -C libft fclean
	@rm -f $(PUSH_SWAP)
	@echo "$(RED)$(PUSH_SWAP) removed"
	@rm -f $(CHECKER)
	@echo "$(CHECKER) removed$(NC)"

re: fclean all
