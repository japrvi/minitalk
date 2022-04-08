SERVER	=	server
CLIENT	=	client
CC		=	gcc
CFLAGS	=	 -Wall -Werror -Wextra -glldb -O0

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o util.o
			$(CC) $(CFLAGS) server.o util.o -o $@

$(CLIENT) : client.o util.o
			$(CC) $(CFLAG) client.o util.o -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -c 

clean :
		rm -rf *.o

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all clean fclean re
