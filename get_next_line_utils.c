/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgacho <roman.gacho@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:27:31 by rgacho            #+#    #+#             */
/*   Updated: 2023/10/26 12:27:31 by rgacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr != NULL)
		ft_memcpy(ptr, s1, len + 1);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i] && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && i < dstsize - dstlen - 1)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joinstr;
	size_t		total_len;

	if (!s1)
		return ft_strdup(s2);
	if (!s2)
		return ft_strdup(s1);

	total_len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = (char *)malloc((total_len + 1) * sizeof(char));
	if (joinstr != NULL)
	{
		ft_strlcpy(joinstr, s1, total_len + 1);
		ft_strlcat(joinstr, s2, total_len + 1);
	}
	return (joinstr);
}

/*node	*crear_nodo(char *content)
{
	node *new_node; // crea un nodo
	new_node = (node *)malloc(sizeof(node)); // asignación de memoria
	if (!new_node)
		return (new_node = NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

node	*encontrar_ultimo_nodo(node *last)
{
	if (last == NULL)
		return (0);
	while (last)
	{
		if (last->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}

void	aniadir_nodo(node **cabecera_nodo, node *new)
{
	node *t;

	if (*cabecera_nodo)
	{
		t = encontrar_ultimo_nodo(*cabecera_nodo); 
		t->next = &*new;
	}
	else
		*cabecera_nodo = new;
}

void    crear_lista(**node lista, int fd) {
	int     char_read;
	char    *buf;
	while(!hay_salto_linea(*lista)) {
		buf = (void *)malloc(buffer_size + 1);
		
		char_read = read(fd, buf, buffer_size);
		buf[char_read] = '\0';
		aniadir_nodo
	}
}*/

int     hay_salto_linea(char *buf) 
{
	int res = 0;
	int i = 0;
	while(buf[i]) {
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char    *cortar_antes_salto(char *buf)
{
	int i = 0;
	char    *str;

	while(buf[i] != '\n' && buf[i])
		i++;
	str = (void *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(str, buf, i + 1);

	return (str);
}

char    *cortar_despues_salto(char *buf)
{
	int i = ft_strlen(buf) - 1;
	char    *str;
	int		new_str_size;
	int	j = 0;
	
	while(buf[i] != '\n' && i >= 0)
		i--;
	new_str_size = ft_strlen(buf) - i;
	str = (void *)malloc(sizeof(char) * new_str_size);

	while (buf[i + 1] != '\0')
		str[j++] = buf[i++ + 1];
	str[j] = '\0';

	// printf("inicio_siguiente obtenido: %s\n", str);
	return (str);
}