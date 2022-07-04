NAME		:= minitalk
SERVER		:= server
CLIENT		:= client
LIBFT		:= libft/libft.a
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
NOLINKING	:=	-c

SRC			:=	server.c \
				client.c \

OBJ			:=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER).o $(LIBFT)
	@$(CC) $(SERVER).o -o $@ libft/libft.a
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

$(CLIENT) : $(CLIENT).o $(LIBFT)
	@$(CC) $(CLIENT).o -o $@ libft/libft.a
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

$(LIBFT) :
	make -C libft

%.o: %.c
	@gcc $(CFLAGS) $(NOLINKING) $< -o $@

clean :
	cd libft && make clean
	@rm -f $(OBJ)
	@printf "\e[38;5;206m.o files deleted\e[0m\n"

fclean: clean
	cd libft && make fclean
	@rm -f $(SERVER) $(CLIENT) *.o
	@printf "\e[38;5;200mBinaries deleted\e[0m\n"

re: fclean all
