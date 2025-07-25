unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	// หาความยาวของ dest
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;

	// หาความยาวของ src
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;

	// ถ้า size น้อยกว่าหรือเท่ากับความยาวของ dest
	// ให้คืนค่า size + src_len
	if (size <= dest_len)
		return (size + src_len);

	// คัดลอก src ไปต่อท้าย dest
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	// ใส่ null terminator
	dest[i] = '\0';

	// คืนค่าความยาวรวมที่พยายามจะสร้าง
	return (dest_len + src_len);
}