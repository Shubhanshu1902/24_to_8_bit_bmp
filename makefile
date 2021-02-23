CC=gcc 
all_sources=main.c file_reader.c conversion.c file_writer.c . #all the .c files which are to be compiled
all_objs=$(all_sources:.c=.o) #onject files created from the .c files

my_project: $(all_objs) #creating excutable file
		$(CC) -o my_project $(all_objs) 
%.o: %.c 				#creating object files
	$(CC) -c $(all_sources) 

clean:		#removing the executable file and the onject file
	rm my_project *.o