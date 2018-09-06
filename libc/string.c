

#include <stddef.h>
#include <string.h>


int strcmp(const char *s1, const char *s2) {
	int i = 0;
	while (*s1 && *s2)
	{
		i++;
		if (*s1 != *s2)
		{
			return *s1 - *s2;
		}
		s1++;
		s2++;
	}
	if (*s1 && (!*s2))
	{
		return 1;
	}
	if (*s2 && (!*s1))
	{
		return -1;
	}
	return 0;
}

size_t strlen(const char *s) {
	size_t size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return size;
}

char *strchr(const char *s, int c) {
	while (*s)
	{
		if (*s == c)
		{
			return (char *)s;
		}
		s++;
	}
	return NULL;
}

size_t strspn(const char *str, const char *accept) {
	size_t result = 0;
	while (*str)
	{
		const char *temp;
		temp = accept;
		while (*temp)
		{
			if (*temp == *str)
			{
				break;
			}
			temp++;
		}
		if (!(*temp))
		{
			return result;
		}
		result++;
		str++;
	}
	return result;
}

size_t strcspn(const char *str, const char *reject) {
	size_t result = 0;
	while (*str)
	{
		const char *temp;
		temp = reject;
		while (*temp)
		{
			if (*temp == *str)
			{
				break;
			}
			temp++;
		}
		if (*temp)
		{
			return result;
		}
		result++;
		str++;
	}
	return result;
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
	char *temp;
	if (str == NULL)
	{
		if (*saveptr == NULL)
		{
			return NULL;
		}
		else
		{
			str = *saveptr;
		}
	}
	while ((strcspn(str, delim) == 0) && *str)
	{
		str++;
	}
	if (*str == '\0')
	{
		str = NULL;
		*saveptr = NULL;
		return str;
	}
	temp = str;
	str = str + strcspn(str, delim);
	while ((strcspn(str, delim) == 0) && *str)
	{
		*str = '\0';
		str++;
	}
	*saveptr = str;
	str = NULL;
	return temp;
}
