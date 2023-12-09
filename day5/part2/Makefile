NAME			= day5_1

SRCS_DIR		= src

OBJS_DIR		= objs

INCLUDES		= includes
LIBFT			= ../../libft/libft.a
LIBFT_DIR		= ../../libft

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

MK_FLAG			= --no-print-directory
RM				= rm -rf

SRCS			= day5_1_ok.c
				  
# Substitute .c with .o 
OBJS			= $(SRCS:%.c=$(OBJS_DIR)/%.o)

#default target
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) && ./$(NAME)

#create .o files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Compiling necessary libs..."
	$(MAKE) $(MK_FLAG) -C $(LIBFT_DIR)
	echo "Finished!"

#remove .o files
clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

#reset - remove and recompile
re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT:
