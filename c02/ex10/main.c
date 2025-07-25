#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

// ฟังก์ชันช่วยแสดงผลลัพธ์
void print_test(const char *test_name, char *dest, const char *src, unsigned int size, unsigned int result)
{
	printf("=== %s ===\n", test_name);
	printf("Source: \"%s\" (length: %u)\n", src, result);
	printf("Destination: \"%s\"\n", dest);
	printf("Size: %u\n", size);
	printf("Return value: %u\n", result);
	printf("Copied characters: %lu\n\n", strlen(dest));
}

int main()
{
	char dest[50];
	unsigned int result;
	
	printf("🧪 Testing ft_strlcpy Function\n");
	printf("================================\n\n");
	
	// Test 1: Normal case
	memset(dest, 'X', sizeof(dest)); // เติม X เพื่อดูว่า null-terminate ถูกต้อง
	dest[49] = '\0';
	result = ft_strlcpy(dest, "Hello World", 20);
	print_test("Test 1: Normal Case", dest, "Hello World", 20, result);
	
	// Test 2: Size เท่ากับความยาว string พอดี
	memset(dest, 'X', sizeof(dest));
	dest[49] = '\0';
	result = ft_strlcpy(dest, "Hello", 6); // 5 chars + 1 null
	print_test("Test 2: Exact Size", dest, "Hello", 6, result);
	
	// Test 3: Size น้อยกว่าความยาว string (truncation)
	memset(dest, 'X', sizeof(dest));
	dest[49] = '\0';
	result = ft_strlcpy(dest, "Hello World", 8);
	print_test("Test 3: Truncation", dest, "Hello World", 8, result);
	
	// Test 4: Size = 1 (เก็บได้แค่ null terminator)
	memset(dest, 'X', sizeof(dest));
	dest[49] = '\0';
	result = ft_strlcpy(dest, "Hello", 1);
	print_test("Test 4: Size = 1", dest, "Hello", 1, result);
	
	// Test 5: Size = 0 (ไม่คัดลอกอะไรเลย)
	strcpy(dest, "Original"); // ใส่ข้อมูลเดิม
	result = ft_strlcpy(dest, "Hello", 0);
	print_test("Test 5: Size = 0", dest, "Hello", 0, result);
	
	// Test 6: Empty string
	memset(dest, 'X', sizeof(dest));
	dest[49] = '\0';
	result = ft_strlcpy(dest, "", 10);
	print_test("Test 6: Empty String", dest, "", 10, result);
	
	// Test 7: Large string
	memset(dest, 'X', sizeof(dest));
	dest[49] = '\0';
	result = ft_strlcpy(dest, "This is a very long string that will be truncated", 15);
	print_test("Test 7: Large String", dest, "This is a very long string that will be truncated", 15, result);
	
	printf("✅ All tests completed!\n");
	printf("\n💡 หมายเหตุ:\n");
	printf("- Return value คือความยาวของ source string เสมอ\n");
	printf("- Destination จะมี null terminator เสมอ (ถ้า size > 0)\n");
	printf("- ถ้า return value >= size แสดงว่าเกิด truncation\n");
	
	return 0;
}
