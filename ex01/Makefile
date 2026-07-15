# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 13:10:43 by snazzal           #+#    #+#              #
#    Updated: 2026/07/15 13:10:59 by snazzal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g
RM = rm -f

all: ${NAME}
${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
