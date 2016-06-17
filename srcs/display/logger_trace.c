#include "logger.h"

void	logger_trace(int fd, char *file, int line, const char *fmt, ...)
{
	va_list	lst;
	char	*time;
	char	*out_info;
	char	*out_mesg;

	if (g_log_lvl < D_TRACE)
		return ;

	time = logger_get_time();
	asprintf(&out_info, "[ %s ] [ %-7s ] (l.%3d) %s -> ", \
			time, "TRACE", line, file);

	va_start(lst, fmt);
	vasprintf(&out_mesg, fmt, lst);
	va_end(lst);

	dprintf(fd, "\033[38;5;239m%s%s\033[0m\n", out_info, out_mesg);

	free(out_info);
	free(out_mesg);
	free(time);
}
