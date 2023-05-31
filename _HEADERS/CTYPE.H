/* ctype.h standard header */
/*******************************************************************************************
 * 本头文件中声明的函数可以用来对字符进行判断和转换，这些字符由fgetc、getc、getchar等函数（都在<stdio.h>
 * 中声明）读入。这些函数只对<stdio.h>中定义的EOF值和unsigned char类型可以代表的值正确工作。当基本C字符集
 * 中的字符表示为char类型的时候，它们为正值，但其他字符可能不是这样。
 *
 * 字符分类函数（一定注意是字符！！并非数字）定义的字符类别有以下几种。
 * 1.数字——一个‘0’~‘9’之间的十进制数
 * 2.十六进制数字——数字，或者字母表的前6个字母‘A’~‘F’或‘a’~‘f’
 * 3.小写字母——‘a’~‘z’中的一个，在"C"区域设置外可能会加上其他的字符
 * 4.大写字母——‘A’~‘Z’中的一个，在"C"区域设置外可能会加上其他的字符
 * 5.字母——小写字母或大写字母，在"C"区域设置外可能会加上其他的字符
 * 6.字母数字——字母或者数字
 * 7.图形字符——占据一个打印位置，输出到显示设备时可见的字符（所以只要能显示的，且占一个打印位的，全都属于）
 * 8.标点符号——非字母数字的图形字符，至少包括表示C源程序文本的29个符号
 * 9.打印字符——图形字符或者空格符‘ ’
 * 10.空格——空格字符‘ ’和5个标准的运动控制字符（换页符FF、换行符NL、回车符CR、水平制表符HT、垂直制表符VT）
 *          在"C"区域设置外可能会加上其他的字符
 * 11.控制字符——是5个标准的运动字符、退格符BS和警报符BEL，加上其他可能的字符中的一个字符
 * 在ASCII中，标点也包括像‘@’和‘$’这样的字符。控制字符包括编码为十进制的1~31之间的所有字符，和编码为127的删除符
 ********************************************************************************************/
#ifndef _CTYPE
#define _CTYPE
		/* _Ctype code bits */
#define _XA		0x200 /* extra alphabetic */
#define _XS		0x100 /* extra space */
#define _BB		0x80 /* BEL, BS, etc. */
#define _CN		0x40 /* CR, FF, HT, NL, VT */
#define _DI		0x20 /* '0'-'9' */ /* D1:0010 0000, '0': 0011 0000~'9': 0011 1001 */
#define _LO		0x10 /* 'a'-'z' */
#define _PU		0x08 /* punctuation */
#define _SP		0x04 /* space */
#define _UP		0x02 /* 'A'-'Z' */
#define _XD		0x01 /* '0'-'9', 'A'-'F', 'a'-'f' */
		/* declarations */
int isalnum(int), isalpha(int), iscntrl(int), isdigit(int);
int isgraph(int), islower(int), isprint(int), ispunct(int);
int isspace(int), isupper(int), isxdigit(int);
int tolower(int), toupper(int);
extern const short *_Ctype, *_Tolower, *_Toupper;
		/* macro overrides */
        /* 判别所有isalpha或者isdigit判别为真的字符 */
#define isalnum(c)	(_Ctype[(int)(c)] & (_DI|_LO|_UP|_XA))
        /* 判别所有isupper或者islower判别为真的字符 */
#define isalpha(c)	(_Ctype[(int)(c)] & (_LO|_UP|_XA))
        /* 判别所有的控制字符 */
#define iscntrl(c)	(_Ctype[(int)(c)] & (_BB|_CN))
        /* 判别所有的十进制数字字符，注意，这里主语最后落到的是字符！即‘1’为真，1为假 */
#define isdigit(c)	(_Ctype[(int)(c)] & _DI)
        /* 判别除空格（‘ ’）之外的所有打印字符 */
#define isgraph(c)	(_Ctype[(int)(c)] & (_DI|_LO|_PU|_UP|_XA))
        /* 判别所有的小写字母 */
#define islower(c)	(_Ctype[(int)(c)] & _LO)
        /* 判别包括空格（‘ ’）在内的所有打印字符 */
#define isprint(c)	\
	(_Ctype[(int)(c)] & (_DI|_LO|_PU|_SP|_UP|_XA))
        /* 判别除空格（‘ ’）和isalnum判别为真之外的所有打印字符 */
#define ispunct(c)	(_Ctype[(int)(c)] & _PU)
        /* 判别所有标准的空白字符，标准空白字符有：空格‘ ’、换页'\f'、
         * 换行'\n'、回车'\r'、水平制表符'\t'、垂直制表符'\v'
         * 在"C"区域设置中，这个函数用来识别输出到显示设备时，所有改变打印位置、却没有显示图形二段字符*/
#define isspace(c)	(_Ctype[(int)(c)] & (_CN|_SP|_XS))
        /* 判别所有大写字母字符 */
#define isupper(c)	(_Ctype[(int)(c)] & _UP)
        /* 判别所有的十六进制数字字符，其定义见头文件开头 */
#define isxdigit(c)	(_Ctype[(int)(c)] & _XD)
        /* 把大写字母转换为相应的小写字母
         * 如果参数被isupper判别为真，且有一个和它对应的islower为真的字符
         * 那么函数toupper就返回这个对应的字符，否则，返回原来的参数值 */
#define tolower(c)	_Tolower[(int)(c)]
        /* 把小写字母转换为相应的大写字母
         * 如果参数被islower判别为真，且有一个和它对应的isupper为真的字符
         * 那么函数toupper就返回这个对应的字符，否则，返回原来的参数值 */
#define toupper(c)	_Toupper[(int)(c)]
#endif
