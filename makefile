CC=gcc
all_sources=main.c file_reader.c conversion.c file_writer.c
my_project: $(all_sources)
		$(CC) -o my_project $(all_sources) 

clean:
	rm my_project tt.bmp 