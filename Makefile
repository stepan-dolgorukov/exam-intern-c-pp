compiler_c := gcc
module := quadratic_equation

lib${module}.so: \
	quadratic_equation.o \
	pair_float.o

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

pair_float.o: \
	pair_float.c

	${compiler_c} \
		-c ${<} \
		-fPIC

pair_float.o: \
	pair_float.h

check.o: \
	check.c

	${compiler_c} \
		-c ${^}

check: \
	check.o

	${compiler_c} \
		-L${PWD} \
		-l${module} \
		-Wl,-rpath=${PWD} \
		${^} \
		-o ${@}