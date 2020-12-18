.PHONY: all clean fclean re

# Name of file
NAME		=	libft.a

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	logs

# List of sources
SRCS_CTYPE	    =	$(addprefix $(PATH_SRC)/ctype/, ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_tolower.c ft_toupper.c)
SRCS_GNL	    =	$(addprefix $(PATH_SRC)/gnl/, get_next_line.c get_next_line_utils.c)
SRCS_LIST	    =	$(addprefix $(PATH_SRC)/list/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)
SRCS_HASH       =   $(addprefix $(PATH_SRC)/hash/, ft_hashnew.c ft_hashprint.c ft_hashlast.c ft_hashadd.c ft_hashfind.c ft_hashdel.c ft_hashclear.c ft_hashlen.c ft_hashdup.c)
SRCS_MEM	    =	$(addprefix $(PATH_SRC)/mem/, ft_calloc.c ft_wrmalloc.c ft_memset.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memrchr.c)
SRCS_PUT	    =	$(addprefix $(PATH_SRC)/put/, ft_putchar.c ft_putstr.c)
SRCS_NUMBER	    =	$(addprefix $(PATH_SRC)/number/, ft_atoi.c ft_digit.c ft_itoa.c)
SRCS_STRING	    =	$(addprefix $(PATH_SRC)/string/, ft_bzero.c ft_chartostr.c ft_strcat.c ft_strcmp.c ft_strichr.c ft_strlen.c ft_substr.c ft_charstr.c ft_split.c ft_strchr.c ft_strdup.c ft_strndup.c ft_strjoin.c ft_strncmp.c ft_strlcpy.c)

# Printf
SRCS_PF_DISP	=	$(addprefix $(PATH_SRC)/printf/display/, pf_disp.c pf_disp_char.c pf_disp_int.c pf_disp_perc.c pf_disp_ptr.c pf_disp_string.c)
SRCS_PF_LISTS	=	$(addprefix $(PATH_SRC)/printf/lists/, pf_initlst.c)
SRCS_PF_UTILS	=	$(addprefix $(PATH_SRC)/printf/utils/, ft_putnbr_format.c ft_putnbr_ui_base_fd.c ft_digit_format_base.c ft_digit_ul_base.c)
SRCS_PF_CORE	=	$(addprefix $(PATH_SRC)/printf/core/, pf_conv.c pf_utils.c ft_printf.c)


SRCS		    =	$(SRCS_CTYPE) $(SRCS_GNL) $(SRCS_LIST) $(SRCS_HASH) $(SRCS_MEM) $(SRCS_PUT) $(SRCS_NUMBER) $(SRCS_STRING) $(SRCS_PF_CORE) $(SRCS_PF_DISP) $(SRCS_PF_LISTS) $(SRCS_PF_UTILS)
OBJS		    =	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		    =	$(addprefix $(PATH_INC)/, libft.h libft_ctype.h libft_gnl.h libft_list.h libft_mem.h libft_number.h libft_put.h libft_string.h)
LOG			    =	$(PATH_LOG)/libft.log

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra
COMP_ADD	=	-I$(PATH_INC)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"
	@ $(RM) -rf $(PATH_LOG)/time.log

init:
	@ $(shell mkdir -p $(PATH_OBJ) $(PATH_LOG))

$(NAME): $(OBJS) $(INCS)
	@ (set -x; ar rcs $(NAME) $(OBJS)) >> $(LOG) 2>&1

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.c $(INCS)
	@ (set -x; $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@) >> $(LOG) 2>&1
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/*/%.c $(INCS)
	@ (set -x; $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@) >> $(LOG) 2>&1
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)
	@ $(RM) -rf $(PATH_LOG)

re: fclean all