CC=gcc
all_sources=main.c file_reader.c conversion.c file_writer.c
all_objs=$(all_sources:.c=.o)

my_project: $(all_objs)
		$(CC) -o my_project $(all_objs) 
%.o: %.c
	$(CC) -c $(all_sources)

clean:
	rm my_project tt.bmp *.o