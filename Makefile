# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 01:15:07 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/09/22 19:37:19 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hashtable
FULLNAME = hashtablefull
LIBNAME = lib$(NAME).a
LIBFULLNAME = lib$(FULLNAME).a
TESTNAME = test
NEARPRMNAMENAME = getnearprime
LIBFTNAME = ft

SRCDIR = src
OBJDIR = objs
NEARPRMDIR = NearestPrime
LIBFTDIR = $(NEARPRMDIR)/lib$(LIBFTNAME)
FTPOWTDIR = ft_pow
FTSQRTPATH = $(NEARPRMDIR)/$(FTPOWTDIR)

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TESTFILE = test.c

NEARPRM_OBJ = $(NEARPRMDIR)/$(OBJDIR)/*.o
LIBFT_OBJ = $(LIBFTDIR)/$(OBJDIR)/*.o
FTSPOW_OBJ = $(FTSQRTPATH)/$(OBJDIR)/*.o
FULLOBJS = $(NEARPRM_OBJ) $(FTSPOW_OBJ) $(LIBFT_OBJ)

CC = gcc
CFLAGSO = -Wall -Wextra -Werror
LIB_FT = -L$(LIBFTDIR) -l$(LIBFTNAME)
LIB_NEARESTPRM = -L$(NEARPRMDIR) -l$(NEARPRMNAMENAME)
LFLAGS = $(LIB_NEARESTPRM) $(LIB_FT)

.PHONY: all, re, lib, libfull, clean, fclean, run

all: lib

lib: $(LIBNAME)

libfull: $(LIBFULLNAME)

clean:
	$(MAKE) -C $(NEARPRMDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(NEARPRMDIR) fclean
	rm -f $(LIBNAME) $(LIBFULLNAME) $(TESTNAME)

re: fclean lib

run: $(LIBFULLNAME)
	$(CC) $(CFLAGSO) $(TESTFILE) -L. -l$(FULLNAME) -o $(TESTNAME)
	./$(TESTNAME)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(NEARPRMDIR) lib
	ar -rc $@ $(OBJ)
	ranlib $@

$(LIBFULLNAME): $(OBJ)
	$(MAKE) -C $(NEARPRMDIR) lib
	ar -rc $@ $(OBJ) $(NEARPRM_OBJ) $(LIBFT_OBJ) $(FTSPOW_OBJ)
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@
 