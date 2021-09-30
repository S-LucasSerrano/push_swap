NAME = push_swap

SRC = $(ROOT_C) $(STACK_SRC) $(OP_SRC) $(ALGO_SRC)
ROOT_C = main.c error.c

# --- STACKS ---
STACK_C = stack_init.c asign_indexes.c stack_mem.c stack_utils.c get_node.c	
STACK_DIR = stack/
STACK_SRC = $(addprefix $(STACK_DIR), $(STACK_C))

# --- OPERATIONS ---
OP_C = swap.c push.c rotate.c reverse_rotate.c operation_utils.c put_on.c
OP_DIR = operations/
OP_SRC = $(addprefix $(OP_DIR), $(OP_C))

# --- ALGORITHMS ---
ALGO_C = insertion_sort.c layer_sort.c sandwich_sort.c
ALGO_DIR = algorithms/
ALGO_SRC = $(addprefix $(ALGO_DIR), $(ALGO_C))

# --- LIBFT ---
LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

# --- OBJ ---
OBJ_DIR = _objFiles/
OBJ_SRC = $(ROOT_C:.c=.o) $(STACK_C:.c=.o) $(OP_C:.c=.o) $(ALGO_C:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_SRC))

# --- FALGS ---
FLAGS = -Wall -Wextra -Werror

# --- COlORS ---
NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'


# --- RULES ---
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FALGS) -c $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Moving object files to $(OBJ_DIR)..." $(NONE)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ_SRC) $(OBJ_DIR)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBF_DIR) clean
	@echo "   - Clean"

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean
	@echo "   - All clean"

re: fclean all

norm: $(SRC)
	@echo $(GRAY) ""
	@norminette $(SRC) *.h */*.h
	@echo $(NONE)$(GREEN) "     NORM OK \n" $(NONE)


# --- TEST ---
n = 0
exe: all
	@if [ $(n) -le 0 ]; then \
			echo "\033[31m     MAKE ERROR"; \
			echo "Usage: \033[0;3;4m< make exe n=x >\033[0;31m. x is the length of the number list and must be above 0."; \
	else \
		ARG=$$(seq -$(n) $(n) | sort -R | head -n $(n) | tr '\n' ' '); \
		echo $(YELLOW) "     -Sorting $(n) numbers..." $(NONE); \
		./push_swap $$ARG; \
	fi;

check: all
	@if [ $(n) -le 0 ]; then \
			echo "\033[31m     MAKE ERROR"; \
			echo "Usage: \033[0;3;4m< make check n=x >\033[0;31m. x is the length of the number list and must be above 0."; \
	else \
		echo $(YELLOW) "     -Sorting $(n) numbers..." $(NONE); \
		ARG=$$(seq -$(n) $(n) | sort -R | head -n $(n) | tr '\n' ' '); \
		echo $(YELLOW) "-NUMBERS:" $(NONE); \
		echo $$ARG; \
		echo $(YELLOW) "-OPERATIONS:" $(NONE); \
		./push_swap $$ARG > .push_swap_output; \
		echo $$(cat .push_swap_output) ; \
		echo $$RES; \
		echo $(YELLOW) "-STEPS:" $(NONE); \
		echo $$(cat .push_swap_output | wc -l) ; \
		echo $(YELLOW) "-CHECKER:" $(NONE); \
		cat .push_swap_output | ./checker $$ARG; \
		rm -rf .push_swap_output ; \
	fi;
