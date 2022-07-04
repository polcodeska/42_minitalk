NAME		:= minitalk
SERVER		:= server
CLIENT		:= client
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
NOLINKING	:=	-c

SRC			:=	server.c \
				client.c \

OBJ			:=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER).o
	@$(CC) $(SERVER).o -o $@
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

$(CLIENT) : $(CLIENT).o
	@$(CC) $(CLIENT).o -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

%.o: %.c
	@gcc $(CFLAGS) $(NOLINKING) $< -o $@

clean :
	@rm -f $(OBJ)
	@printf "\e[38;5;206m.o files deleted\e[0m\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT) *.o
	@printf "\e[38;5;200mBinaries deleted\e[0m\n"

re: fclean all
