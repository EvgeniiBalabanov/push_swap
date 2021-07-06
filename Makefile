.PHONY:			all tools re clean fclean debug bonus

NAME_1		=	push_swap

NAME_2		=	checker

CC			=	gcc

LIBS		=	$(addprefix ./tools/, libft list dlist)

CFLAGS		=	-I ./programs/push_swap/includes\
				-I ./programs/checker/includes\
				$(addprefix -I, $(addsuffix /includes/, . $(LIBS)))

FILES_1		=	$(addprefix programs/push_swap/src/,\
					main.c start.c exit.c\
					parse_agrums.c add_move.c\
					optimizer.c\
					$(addprefix group/,\
						add_back.c add_front.c create.c del_back.c\
						del_front.c index.c swap.c delone.c transer_number.c\
						del_first_group.c\
					)\
					$(addprefix logic/,\
						check_finish.c from_a.c from_b.c clean_group.c\
						from_a_last_part.c from_b_setting_group.c\
						from_b_first_part.c\
					)\
					$(addprefix number/,\
						create.c round.c\
					)\
				)

FILES_2		=	$(addprefix programs/checker/src/,\
					main.c parse_and_run_command.c\
					parse_argums.c print_result.c\
					show_process.c exit.c read_line.c\
					$(addprefix command/,\
						pa.c pb.c ra.c rb.c rr.c\
						rra.c rrb.c rrr.c sa.c sb.c ss.c\
					)\
				)

OBJS_1		=	$(FILES_1:.c=.o)
OBJS_2		=	$(FILES_2:.c=.o)

all:			$(NAME_1) $(NAME_2)

bonus:			all

debug:			CFLAGS  += -fsanitize=address -g
debug:			all;

$(NAME_1):	$(OBJS_1) | tools
	$(CC) $(CFLAGS) $(OBJS_1) -o $(NAME_1) -lft -llist -ldlist $(addprefix -L, $(LIBS))

$(NAME_2):	$(OBJS_2) | tools
	$(CC) $(CFLAGS) $(OBJS_2) -o $(NAME_2) -lft -llist -ldlist $(addprefix -L, $(LIBS))

define		ft_tools
	for library in $(LIBS) ; do \
		make $(1) -C $$library ;\
	done
endef

tools:
	$(call ft_tools, )

clean:
	$(call ft_tools, clean)
	rm -rf $(OBJS_1) $(OBJS_2)

fclean:			clean
	rm -rf $(NAME_1) $(NAME_2)
	$(call ft_tools, fclean)

re:				fclean all
