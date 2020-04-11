CC=gcc

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
FLAGGLUT=-lglut -lGL -lGLU
endif
ifeq ($(UNAME_S),Darwin)
FLAGGLUT=-Wno-deprecated-declarations -framework OpenGL -framework GLUT
endif

FLAG=-Wall -std=c99 -Wno-unused-const-variable
SRCS= gameOption.c \
home.c \
rules.c \
game.c \
scoreLevel.c \
liveLevel.c \
greenplanetLevel.c \
ammunitionLevel.c \
random.c \
ennemy.c \
biker.c \
collision.c \
tree.c \
main.c \

OBJET = $(SRCS:.c=.o)
EXEC= program



all: $(EXEC)

$(EXEC): $(SRCS)
	$(CC) -c $(SRCS) $(FLAG) $(FLAGGLUT)
	$(CC) -o $(EXEC) $(OBJET) $(FLAG) $(FLAGGLUT)
	
clean:
	rm -rf $(EXEC)
	rm -rf *.o