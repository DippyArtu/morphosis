/* *********************************** */
/*                                     */
/*      Morphosis project              */
/*                                     */
/*      Created by Artur Makhnach      */
/*      github.com/DippyArtu           */
/*      artum.me                       */
/*                                     */
/* *********************************** */

#include <morphosis.h>
#include <libft.h>

static void					free_matrix1(int ***m)
{
	int						i;
	int						j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			free(m[i][j]);
			j++;
		}
		free(m[i]);
		i++;
	}
	free(m);
	m = NULL;
}

static void					free_matrix2(int **m)
{
	int						i = 0;

	while (i < 6)
	{
		free(m[i]);
		i++;
	}
	free(m);
	m = NULL;
}

static int					***alloc_matrix1(void)
{
	int						***matrix;
	int						i = 0;
	int						j = 0;

	matrix = (int ***)malloc(sizeof(int **) * 6);
	while (i < 6)
	{
		matrix[i] = (int **)malloc(sizeof(int *) * 6);
		j = 0;
		while (j < 6)
		{
			matrix[i][j] = (int *)malloc(sizeof(int) * 6);
			for (int n = 0; n < 6; n++)
				matrix[i][j][n] = 0;
			j++;
		}
		i++;
	}
	return(matrix);
}

static int					**alloc_matrix2(void)
{
	int						**matrix;
	int						i = 0;

	matrix = (int **)malloc(sizeof(int *) * 6);
	while (i < 6)
	{
		matrix[i] = (int *)malloc(sizeof(int) * 6);
		for (int n = 0; n < 6; n++)
			matrix[i][n] = 0;
		i++;
	}
	return(matrix);
}

static int					bin_to_dec(char *bin)
{
	int						binary[6];
	int						pwr = 5;
	int						res = 0;

	for (int i = 0; i < 6; i++)
	{
		binary[i] = bin[i] - 48;
		res = res + (binary[i] * pow(2, pwr));
		pwr--;
	}
	return(res);
}

static void					fill_matrix(int **matrix, int number, int reset)
{
	static int				row = 0;
	static int				col = 0;

	if (row < 6 && col < 6)
	{
		matrix[col][row] = number;
		row++;
	}
	else if (row == 6 && col < 6)
	{
		row = 0;
		col++;
		matrix[col][row] = number;
		row++;
	}
	if (reset == 35)
	{
		row = 0;
		col = 0;
	}
}

static int					***parse_data(int fd, char *line)
{
	int						line_c;
	int						i;
	int						j;
	char					*tmp;
	char					*bin;
	int						***matrix;
	int						nbr;

	int 					c_t = 0;
	int						dim = 0;

	matrix = alloc_matrix1();
	while ((get_next_line(fd, &line)))
	{
		line_c = 0;
		while (line[line_c])
		{
			bin = (char *)malloc(sizeof(char) * 6);
			tmp = (char *)malloc(sizeof(char) * 12);
			ft_bzero(tmp, 12);
			ft_bzero(bin, 6);
			tmp = ft_strncpy(tmp, &line[line_c], 12);
			i = 0;
			j = 0;
			while (tmp[i])
			{
				if (tmp[i] == 48 || tmp[i] == 49)
				{
					bin[j] = tmp[i];
					j++;
				}
				i++;
			}
			nbr = bin_to_dec(bin);
			if (c_t == 36)
			{
				c_t = 0;
				dim++;
			}
			fill_matrix(matrix[dim], nbr, c_t);
			free(bin);
			free(tmp);
			line_c += 12;
			c_t++;
		}
		free(line);
	}
	free(line);
	line = NULL;
	return(matrix);
}

static int					**find_mean(int	***matrix)
{
	int						**mean;
	int						dim = 0;
	int						row = 0;
	int						col = 0;
	int						i = 0;
	int						j = 0;
	int						res = 0;

	mean = alloc_matrix2();
	while (col < 6)
	{
		dim = 0;
		row = 0;
		res = 0;
		j = 0;
		while (row < 6)
		{
			dim = 0;
			res = 0;
			while (dim < 6)
			{
				res += matrix[dim][col][row];
				dim++;
			}
			res /= 6;
			mean[i][j] = res;
			row++;
			j++;
		}
		col++;
		i++;
	}
	return(mean);
}

void							process_matrix(char *file, t_mat_conv_data *data)
{
	int						fd;
	int						fd_result_mean;
	char					*line;
	int						***decimals;
	int						**mean;

	decimals = NULL;
	mean = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		error(OPEN_FILE_ERR, NULL);
	decimals = parse_data(fd, line);
	mean = find_mean(decimals);
	free_matrix1(decimals);
	matrix_hash(mean, data);
	free_matrix2(mean);
	close(fd);
	printf("Matrix processed\n");
}