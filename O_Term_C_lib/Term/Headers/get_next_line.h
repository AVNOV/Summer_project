#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE 64
#endif /* !READ_SIZE */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
