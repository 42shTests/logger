#include "logger.h"

void	logger_fatal(int fd, char *file, int line, const char *fmt, ...)
{
	va_list	lst;
	char	*time;
	char	*out_info;
	char	*out_mesg;

	if (g_log_lvl < D_FATAL)
		return ;

	time = logger_get_time();
	asprintf(&out_info, "\033[31m[ %s ] [ %-7s ] (l.%3d) %s -> \033[0m", \
			time, "FATAL", line, file);

	va_start(lst, fmt);
	vasprintf(&out_mesg, fmt, lst);
	va_end(lst);

	dprintf(fd, "%s%s\n", out_info, out_mesg);

	free(out_info);
	free(out_mesg);
	free(time);
}
