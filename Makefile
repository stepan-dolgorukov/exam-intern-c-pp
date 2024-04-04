compiler_c := gcc
module := quadratic_equation

lib${module}.so: \
	quadratic_equation.o

	${compiler_c} \
		${^} \
		-o ${@} \
		-shared \
		-lm

quadratic_equation.o: \
	quadratic_equation.c

	${compiler_c} \
		-c ${<} \
		-fPIC

quadratic_equation.o: \
	quadratic_equation.h


test.o: \
	test.c

	${compiler_c} \
		-c ${^}

test: \
	test.o

	${compiler_c} \
		-L${PWD} \
		-l${module} \
		-Wl,-rpath=${PWD} \
		${^} \
		-o ${@}