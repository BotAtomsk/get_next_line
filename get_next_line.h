/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgacho <roman.gacho@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:27:34 by rgacho            #+#    #+#             */
/*   Updated: 2023/10/26 12:27:34 by rgacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10
#endif

typedef struct l_node {
	// atributos
	char                *content;
	struct l_node       *next;
} node;

char    *get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int     hay_salto_linea(char *buf);
char    *cortar_antes_salto(char *buf);
char    *cortar_despues_salto(char *buf);
