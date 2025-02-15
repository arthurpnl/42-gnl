# Nom de la bibliothèque
NAME = get_next_line.a

# Fichiers sources
SRCS = get_next_line.c get_next_line_utils.c

# Objets correspondants
OBJS = $(SRCS:.c=.o)

# Flags de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Commandes standard
AR = ar rcs
RM = rm -f

# Règle par défaut : compilation de la bibliothèque
all: $(NAME)

# Compilation des fichiers objets et création de la bibliothèque
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)

# Nettoyage complet (objets + bibliothèque)
fclean: clean
	$(RM) $(NAME)

# Recompile tout proprement
re: fclean all

# Indique que ces règles ne sont pas des fichiers
.PHONY: all clean fclean re
