# dnsw Makefile
# TODO: Modify Makefile to use makedeps so that changes to headers also cause
# rebuild.
# TODO: Better understand order-only dependencies.

PROJECT_NAME = dnsw

CC ?= clang
CXX ?= clang

SRCDIR = src
OBJDIR = out

INCLUDES = -Iinlcude
CFLAGS = -Wall
LDFLAGS = 

SRC_FILES = $(wildcard ${SRCDIR}/*.c)
OBJ_FILES = $(addprefix ${OBJDIR}/, $(notdir $(SRC_FILES:.c=.o)))

.PHONY: all clean
all: ${PROJECT_NAME}

${PROJECT_NAME}: ${OBJ_FILES}
	${CC} -o ${OBJDIR}/$@ $^ ${LDFLAGS} 
	ln -fs ${OBJDIR}/$@ ${PROJECT_NAME}

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${OBJDIR}:
	mkdir -pv ${OBJDIR}

clean:
	rm -Rf ${OBJDIR}
