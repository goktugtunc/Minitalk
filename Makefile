NAME = client

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra client.c -o client
	gcc -Wall -Werror -Wextra server.c -o server

bonus:
	gcc -Wall -Werror -Wextra client_bonus.c -o client_bonus
	gcc -Wall -Werror -Wextra server_bonus.c -o server_bonus

clean:
	rm -rf client server client_bonus server_bonus

fclean: clean

re: fclean all