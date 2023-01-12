# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 00:45:13 by idouidi           #+#    #+#              #
#    Updated: 2023/01/12 14:19:00 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR 		= ./srcs
SRCS     	= $(shell find $(SRCDIR) -name "*.cpp")
OBJS		= $(SRCS:.cpp=.o)
CXX			=  c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address 
INCLUDES 	= $(shell find . -type f -name "*.hpp" | cut -c 3-)
NAME		= ft_containers
SWAP_COMPIL = 1

###################################################

all			: other

###################################################

%.o			: %.cpp $(INCLUDES)
ifeq ($(SWAP_COMPIL), 1)
	@$(CXX) $(CXXFLAGS) -D STD=1 -c $< -o $@ ;
else
	@$(CXX) $(CXXFLAGS) -D STD=2 -c $< -o $@ ;
endif

###################################################

$(NAME)		: $(OBJS) $(INCLUDES)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
ifeq ($(SWAP_COMPIL), 1)
	@./$(NAME)
endif
	@make clean

###################################################

other		: $(NAME)
	@clear
	@make -e  --no-print-director SWAP_COMPIL=2 $(NAME)
	@make print

####################################################

clean		:
	@rm -rf $(OBJS)

####################################################

fclean		: clean
	@rm -rf $(NAME)
	@ rm -rf $(shell find . -type f -name "*.diff" | cut -c 3-)

####################################################

re			: fclean all

####################################################

.PHONY: all clean fclean re print other

####################################################

print :
	@echo " \n \
███████╗████████╗  ░█████╗░░█████╗░███╗░░██╗████████╗░█████╗░██╗███╗░░██╗███████╗██████╗░░██████╗"
	@echo "\
██╔════╝╚══██╔══╝  ██╔══██╗██╔══██╗████╗░██║╚══██╔══╝██╔══██╗██║████╗░██║██╔════╝██╔══██╗██╔════╝"
	@echo "\
█████╗░░░░░██║░░░  ██║░░╚═╝██║░░██║██╔██╗██║░░░██║░░░███████║██║██╔██╗██║█████╗░░██████╔╝╚█████╗░"
	@echo "\
██╔══╝░░░░░██║░░░  ██║░░██╗██║░░██║██║╚████║░░░██║░░░██╔══██║██║██║╚████║██╔══╝░░██╔══██╗░╚═══██╗"
	@echo "\
██║░░░░░░░░██║░░░  ╚█████╔╝╚█████╔╝██║░╚███║░░░██║░░░██║░░██║██║██║░╚███║███████╗██║░░██║██████╔╝"
	@echo "\
╚═╝░░░░░░░░╚═╝░░░  ░╚════╝░░╚════╝░╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝╚══════╝╚═╝░░╚═╝╚═════╝░\n"

####################################################

#  🚧 ==> progress 
#  💥 ==> crash
#  ✅ ==> finish
#  🏆 == > success
#  📌 ==> immportant part
#  💡 ==> propose an idea
#  📚 ==> brief

##########################################################
