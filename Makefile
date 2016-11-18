CFLAGS = -march=native -O2 -Wall -pedantic
PREFIX = /usr/local
NAME = lorem

CFILES = main.c

all: ${CFILES}
	${CC} ${CFLAGS} ${CFILES} -o ${NAME}

install: all
	@echo installing executable file to ${PREFIX}/bin
	@mkdir -p ${PREFIX}/bin
	@cp -f ${NAME} ${PREFIX}/bin
	@chmod 755 ${PREFIX}/bin/${NAME}

uninstall:
	@echo removing executable file from ${PREFIX}/bin
	@rm -f ${PREFIX}/bin/${NAME}
