char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	// หาตำแหน่งสิ้นสุดของ dest
	while (dest[i] != '\0')
		i++;
	
	j = 0;
	// คัดลอก src ต่อท้าย dest
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	
	// เพิ่ม null terminator
	dest[i] = '\0';
	
	return (dest);
}
