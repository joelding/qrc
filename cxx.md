<<<<<<< HEAD
# C/C++

This document collects ideas to improve the source code.

## Style

* 0000000000000 can disable a section of codes and arouse attention. 18/06/29

``````````````````````````````````````````````````````````````````````````
#if 000000000000000000000000000000000
for (i = 0; i < 100; ++i) {
	i *= 2;
}
#endif /* 000000000000000000000000000000000 */
``````````````````````````````````````````````````````````````````````````


---------------------------------------------------------------------------
How to improve the following code? 
How to specify the size of enum type in C so that the enum can fit into unsigned char STATE?

```
enum
{
	NO_ERROR	=	0,
	UNKNOWN_CMD	=	1,
	DATA_ERROR	=	2,
	UART_TIMEOUT	=	3,
	
	REPLY_STATE_MAX
};

typedef union 
{
#pragma pack(push) /* align to 1 byte instead of an integer 4 bytes */
#pragma pack(1)
	struct {
		unsigned char RPL[2];
		unsigned char COMMAND;
		unsigned char STATE; //NO_ERROR, UNKNOWN_CMD, DATA_ERROR, UART_TIMEOUT
		unsigned char SEQUENCE;
		unsigned char FRAGMENT;
		unsigned char LENGTH;
		unsigned char PAYLOAD[REPLY_PAYLOAD_MAX]; 
		unsigned int CHECKSUM;
		unsigned char STOP_BYTE;
	} m; //member
#pragma pack(pop)

	unsigned char data[COMMAND_LEN];
} UBUS_REPLY;
```

https://gcc.gnu.org/onlinedocs/gcc-4.8.5/gcc/Type-Attributes.htmls://gcc.gnu.org/onlinedocs/gcc-4.8.5/gcc/Type-Attributes.html

```
#include <stdio.h>
/* This attribute, attached to struct or union type definition, specifies that 
 * each member (other than zero-width bit-fields) of the structure or union is 
 * placed to minimize the memory required.
 */

typedef struct __attribute__ ((__packed__)) _struct_t
{
	char c;
	int i;
	struct _struct_t *p;
} struct_t;

/* When attached to an enum definition, it indicates that the smallest integral 
 * type should be used. 
 */

typedef enum __attribute__ ((__packed__))
{
	STATE_0,
	STATE_1,
	STATE_2,
} state_t;

int main(int argc, char *argv[])
{
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(struct _struct_t *) = %lu\n", sizeof(struct _struct_t *));
	printf("sizeof(struct_t) = %lu\n", sizeof(struct_t));
	printf("sizeof(state_t) = %lu\n", sizeof(state_t));
	return 0;
}
```
The result looks like the following:
```
$ ./a.out 
sizeof(char) = 1
sizeof(int) = 4
sizeof(struct _struct_t *) = 8
sizeof(state_t) = 1
sizeof(struct_t) = 14
```
=======
# C++

---
references:

---

## Data Types
- bool
- char
- int, short, long
- float, double, long double
## Literal Constant

## Arithmetic operators
- +, -, *, /, %
- implicit type conversion
- explicit type conversion `static_case<type>(variable)`
```
int number = 10;
cout << static_cast<double><number) / 3;
printf("%f", (double)number / 3);
```


> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbNzQwOTQ2ODA3XX0=
-->

>>>>>>> stackedit/master
