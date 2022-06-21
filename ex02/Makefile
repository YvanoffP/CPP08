NAME = span
NAME_e = span_eval
NAME_l = span_list

SRCS =		main.cpp
SRCS_e =	main_eval.cpp
SRCS_l =	main_list.cpp

CC = c++
FLAGS = -Wall -Wextra -Werror -pedantic
CPP_FLAGS = -std=c++98

OBJS = $(SRCS:.cpp=.o)
OBJSe = $(SRCS_e:.cpp=.o)
OBJSl = $(SRCS_l:.cpp=.o)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

%.o: %.cpp
			@echo $(Y)Compiling [$<]...$(X)
			@$(CC) $(FLAGS) $(CPP_FLAGS) -c $< -o $@
			@printf $(UP)$(CUT)

$(NAME) :	$(OBJS)
			@echo $(Y)Compiling [$(SRCS)]...$(X)
			@echo $(G)Finished [$(SRCS)]$(X)
			@echo
			@echo $(Y)Compiling [$(NAME)]...$(X)
			@$(CC) $(FLAGS) $(CPP_FLAGS) -o $(NAME) $(OBJS)
			@echo $(G)Finished [$(NAME)]$(X)

$(NAME_e) :	$(OBJSe)
			@echo $(Y)Compiling [$(SRCS_e)]...$(X)
			@echo $(G)Finished [$(SRCS_e)]$(X)
			@echo
			@echo $(Y)Compiling [$(NAME_e)]...$(X)
			@$(CC) $(FLAGS) $(CPP_FLAGS) -o $(NAME_e) $(OBJSe)
			@echo $(G)Finished [$(NAME_e)]$(X)

$(NAME_l) :	$(OBJSl)
			@echo $(Y)Compiling [$(SRCS_l)]...$(X)
			@echo $(G)Finished [$(SRCS_l)]$(X)
			@echo
			@echo $(Y)Compiling [$(NAME_l)]...$(X)
			@$(CC) $(FLAGS) $(CPP_FLAGS) -o $(NAME_l) $(OBJSl)
			@echo $(G)Finished [$(NAME_l)]$(X)

eval: $(NAME_e)

list: $(NAME_l)

clean:
			@rm -rf $(OBJS) $(OBJSe) $(OBJSl)
			@echo $(R)Removed [$(OBJS)][$(OBJSe)][$(OBJSl)]$(X)

fclean: clean
			@rm -rf $(NAME) $(NAME_e) $(NAME_l)
			@echo $(R)Removed [$(NAME)][$(NAME_e)][$(NAME_l)]$(X)

re : fclean all

.PHONY: all clean fclean re eval list
