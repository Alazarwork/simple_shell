       #define _GNU_SOURCE
       #include <stdio.h>
       #include <stdlib.h>

       int
       main(int argc, char *argv[])
       {
           FILE *s;
           char *line = NULL;
           size_t len = 0;
           ssize_t nread;

           if (argc != 2) {
               fprintf(stderr, "Usage: %s <file>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           s = fopen(argv[1], "r");
           if (s == NULL) {
               perror("fopen");
               exit(EXIT_FAILURE);
           }

           while ((nread = getline(&line, &len, s)) != -1) {
               printf("Retrieved line of length %zd:\n", nread);
               fwrite(line, nread, 1, stdout);
           }

           free(line);
           fclose(s);
           exit(EXIT_SUCCESS);
       }
