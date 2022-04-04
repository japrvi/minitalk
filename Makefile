SERVER	=	server
CLIENT	=	client
CC		=	gcc
FLAGS	=	 -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o util.o
			$(CC) server.o util.o -o $@

$(CLIENT) : client.o util.o
			$(CC) client.o util.o -o $@

%.o : %.c
	$(CC) $(FLAGS) $< -c 

clean :
		rm -rf *.o

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all clean fclean re
