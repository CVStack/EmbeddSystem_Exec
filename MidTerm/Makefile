CC= gcc
APP=cli
CFLAGS = -D_REENTRANT 
LDFLAGS = -lpthread 
OBJS=cli.o

all: $(APP)
$(APP): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	rm -f *~ $(OBJS) $(APP)


