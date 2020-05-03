CC= gcc
APP=SERVER
CFLAGS = -D_REENTRANT 
LDFLAGS = -lpthread 
t1=Server
t2=List
SRC=$(t1).c $(t2).c

all: $(APP)
$(APP): $(objs) 
	$(CC) $(CFLAGS) -o $@ ${SRC} $^ $(LDFLAGS)
clean:
	rm -f $(APP)


