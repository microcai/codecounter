all : counter

counter : main.c 
	cc $(CFLAGS) $(LDFLAGS)  $< -o $@ 

clean:
	${RM} counter *.o 
