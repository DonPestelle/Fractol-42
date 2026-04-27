# ================================================= #
#                                                   #
#   fractol · 42 Barcelona · by pestell2            #
#                                                   #
# ================================================= #

NAME        := fractol
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
RM          := rm -f

SRCDIR      := src
INCDIR      := includes
OBJDIR      := obj
MLX_DIR     := minilibx-linux
MLX_LIB     := $(MLX_DIR)/libmlx.a
MLX_FLAGS   := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC := $(SRCDIR)/main.c $(SRCDIR)/parse.c $(SRCDIR)/parse_utils.c \
       $(SRCDIR)/view.c $(SRCDIR)/image.c $(SRCDIR)/render.c \
       $(SRCDIR)/fractals.c $(SRCDIR)/cpx.c $(SRCDIR)/color.c \
       $(SRCDIR)/hooks.c

OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ---- colors ---------------------------------------- #
GRN  := \033[0;32m
YEL  := \033[0;33m
CYN  := \033[0;36m
RED  := \033[0;31m
RST  := \033[0m
BLD  := \033[1m

# ---- rules ----------------------------------------- #

all: _header $(NAME) _footer
_header:
	@printf "$(GRN)\n"
	@printf "░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░\n"
	@printf "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n"
	@printf "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n"
	@printf "░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n"
	@printf "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n"
	@printf "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░\n"
	@printf "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░   ░▒▓██████▓▒░░▒▓████████▓▒░\n"
	@printf "$(RST)"
	@printf "$(GRN)$(BLD)  [ 42 Barcelona ]  [ pestell2 ]  [ v1.0 ]$(RST)\n"
	@printf "$(CYN)  -------------------------------------------------------$(RST)\n"
	@printf "$(GRN)  >> INITIALIZING BUILD SEQUENCE...$(RST)\n"
	@sleep 0.3
	@printf "$(GRN)  >> LOADING MODULES...$(RST)\n"
	@sleep 0.2
	@printf "$(GRN)  >> COMPILING FRACTAL ENGINE...$(RST)\n\n"
$(NAME): $(MLX_LIB) $(OBJ)
	@printf "\n$(CYN)  -------------------------------------------------------$(RST)\n"
	@printf "$(GRN)  >> LINKING BINARY...$(RST)\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GRN)  >> BINARY READY: [ $(NAME) ]$(RST)\n"

$(MLX_LIB):
	@printf "$(YEL)  >> LOADING MINILIBX GRAPHICS DRIVER...$(RST)\n"
	@$(MAKE) -C $(MLX_DIR) --silent 2>&1 >/dev/null || \
		(printf "$(RED)  >> ERROR: DRIVER LOAD FAILED$(RST)\n" && $(MAKE) -C $(MLX_DIR) && exit 1)
	@printf "$(YEL)  >> GRAPHICS DRIVER OK$(RST)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@printf "$(GRN)  >> ENCRYPTING MODULE  %-30s$(RST)\n" "$<"
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLX_DIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

_footer:
	@printf "$(CYN)  -------------------------------------------------------$(RST)\n"
	@printf "$(GRN)$(BLD)  >> ACCESS GRANTED$(RST)\n\n"
	@printf "$(GRN)  >> EXECUTE:$(RST)\n"
	@printf "$(CYN)     ./fractol mandelbrot$(RST)\n"
	@printf "$(CYN)     ./fractol julia -0.7269 0.1889$(RST)\n"
	@printf "$(CYN)     ./fractol burning_ship$(RST)\n"
	@printf "$(CYN)     ./fractol tricorn$(RST)\n"
	@printf "$(GRN)\n  >> GOOD LUCK, HACKER.$(RST)\n\n"

clean:
	@printf "$(RED)  >> PURGING OBJECT FILES...$(RST)\n"
	@$(RM) -r $(OBJDIR)
	@$(MAKE) -C $(MLX_DIR) clean --silent 2>/dev/null || true
	@printf "$(RED)  >> DONE$(RST)\n"

fclean: clean
	@printf "$(RED)  >> WIPING BINARY [ $(NAME) ]...$(RST)\n"
	@$(RM) $(NAME)
	@printf "$(RED)  >> SYSTEM CLEAN$(RST)\n"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus _header _footer
