/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgacho <roman.gacho@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:26:36 by rgacho            #+#    #+#             */
/*   Updated: 2023/10/26 12:26:36 by rgacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd) {
	char	*next_line = NULL;
	char	*temp;
	int     chars_read;
	char    buf[256];

	static char 	*inicio_siguiente = NULL;

	if (inicio_siguiente != NULL) {
		temp = ft_strdup(inicio_siguiente);
		free(inicio_siguiente);
		inicio_siguiente = NULL;
		next_line = ft_strdup(temp);
		free(temp);
		
	}

	while((chars_read = read(fd, buf, BUFFER_SIZE))) {
		//crear_lista(&lista, fd);

		buf[chars_read] = '\0';

		//printf("\tvalor buf: %s\n", buf);
		//printf("\tvalor next_line: %s\n", next_line);

		// tratar el buf para que coja solo los caracteres antes de un \n

		if(hay_salto_linea(buf)) {
			temp = cortar_antes_salto(buf);
			inicio_siguiente = cortar_despues_salto(buf);
		}
		else {
			temp = ft_strdup(buf);
			inicio_siguiente = NULL;
		}
			
		
		next_line = ft_strjoin(next_line, temp);
		free(temp);

		// condición de salida
		if(hay_salto_linea(buf)) {
			break;
		}
	}

	return (next_line);
}