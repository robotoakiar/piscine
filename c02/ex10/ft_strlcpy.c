unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	len_src = 0;
	while (src[len_src] != '\0') // คำนวณความยาว src ก่อน
		len_src++;

	i = 0;
	if (size > 0) // ตรวจสอบ size > 0 เพื่อหลีกเลี่ยง size - 1 เป็นค่าลบเมื่อ size เป็น 0
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0'; // ตรวจสอบให้แน่ใจว่ามีการ null-terminate เสมอ
	}
	return (len_src);
}