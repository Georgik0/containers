name = containers
test = test

src_test = main_test.cpp iterator/reverse_iterator_test.cpp vector/vector_test.cpp

objdir = objs
obj_test = ${src_test:%.cpp=${objdir}/%.o}
deps_test = ${obj_test:%.o=%.d}

cc = clang++ -g
flags = -std=c++11

$(test): $(obj_test)
	$(cc) $(flags) $(obj_test) -o $@

-include $(deps_test)
$(objdir)/%.o:	%.cpp Makefile
	@mkdir -p $(objdir)/iterator $(objdir)/vector
	$(cc) $(flags) -MMD -c $< -o $@

all: ${test}

clean:
		rm -rf objs/

fclean:	clean

re:	fclean all
