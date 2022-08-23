#include "pipex.h"
#include "./ft_printf/ft_printf.h"

char    *find_path(char *cmd, const char **envp);

int	main(int argc, char *argv[], const char *envp[])
{
	ft_printf("PATH: %s\n", find_path(argv[2], envp));
	ft_printf("%s\n", argv[2]);
	ft_printf("%i\n", argc);
	return (0);
}
