##
## EPITECH PROJECT, 2024
## {Workshop} Programming Language
## File description:
## Makefile
##

CC			:=	gcc
NAME		:=	corth
CPPFLAGS	:=	-Iinclude/
CFLAGS 		:=	-Wall -Wextra -Werror -pedantic -ansi -fPIE 		 \
				-fno-delete-null-pointer-checks -fno-strict-overflow \
				-fno-strict-aliasing -ftrivial-auto-var-init=zero    \
				-Wformat -Wimplicit-fallthrough 					 \
				-U_FORTIFY_SOURCE -D_GLIBCXX_ASSERTIONS 			 \
				-fstack-protector-strong -g

ifeq ($(PLATFORM),x86_64)
CFLAGS		+=	-fcf-protection=full -Wl,-z,nodlopen -Wl,-z,noexecstack \
				-Wl,-z,relro -Wl,-z,now -fstack-clash-protection 		\
				-fstrict-flex-arrays=3 -Wtrampolines
endif

ifeq ($(PLATFORM),aarch64)
CFLAGS		+=	-mbranch-protection=standard
endif

SRCS			:=	$(shell find src -name '*.c')
OBJS			:=	$(SRCS:.c=.o)

VALGRIND_FLAGS	:=	-s							\
					--leak-check=full			\
					--track-origins=yes			\
					--read-var-info=yes			\
					--trace-children=yes		\
					--show-leak-kinds=all		\
					--read-inline-info=yes		\
					--errors-for-leak-kinds=all

RM				:=	rm -f

all:	$(OBJS)
	$(MAKE) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJS) -o $@

valgrind:	$(NAME)
	valgrind $(VALGRIND_FLAGS) ./$(NAME) example/turing_complete.src

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all
