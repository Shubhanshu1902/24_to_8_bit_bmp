CC=gcc
read: main.c file_reader.c conversion.c file_writer.c
		$(CC) -o main main.c file_reader.c conversion.c file_writer.c

clean:
	rm main tt.bmp result.bmp