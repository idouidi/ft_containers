# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 00:45:13 by idouidi           #+#    #+#              #
#    Updated: 2022/10/15 21:12:11 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/main.cpp srcs/vector/vector_tester.cpp
OBJS		= $(SRCS:.cpp=.o)
CXX			=  c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address 
INCLUDES 	= $(shell find . -type f -name "*.hpp" | cut -c 3-)
NAME		= ft_containers


%.o			: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)		: $(OBJS) $(INCLUDES)
	$(CXX) $(CXXFLAGS)  -o $(NAME) $(OBJS)

all			: $(NAME)

clean		:
	rm -rf $(OBJS)

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY: all clean fclean re