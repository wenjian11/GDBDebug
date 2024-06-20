## ��زο�����
- https://wizardforcel.gitbooks.io/100-gdb-tips/content/set-step-mode-on.html
- https://wizardforcel.gitbooks.io/100-gdb-tips/content/set-step-mode-on.html

## ���ó������в���
- ����`set args 10 20 30 40`

![alt text](image-1.png)

- ʹ��`show args`��ʾ���úõ����в���

![alt text](1717940432579.jpg)

## `path` �����������û���ʾ��ǰ������·���б���Щ·�����ڲ��ҿ�ִ���ļ���Դ�ļ��ͷ����ļ��ȡ��ڵ��Թ����У�GDB �ᰴ��ָ����·��˳��������Щ�ļ���
- `show path`����`show paths`�鿴����·��
## `set environment varname [=value]`�����������û��޸ĵ��Թ�����ʹ�õĻ����������������������ڵ��Գ���ʱָ���ض��Ļ�������ֵ����Щֵ��Ӱ�챻���Գ������Ϊ��
- ����`set environment PATH = /usr/local/bin:/usr/bin:/bin`�޸�PATH��ֵ��
## `unset environment`ȡ����������
- `unset environment LD_LIBRARY_PATH`
## `show environment`��ʾ��ǰ��������
## ����Ŀ¼
- `cd dir` ����ָ��Ŀ¼
- `pwd` ��ʾ��ǰ����Ŀ¼
## ������������
- `info terminal` ��ʾ�����õ����ն˵�ģʽ
- ʹ���ض�����Ƴ������ `run > outfile`
- `tty` ��������ָ�������Գ�������������նˣ��������Գ�������������ض���һ���ض����ն��豸���Ӷ��� GDB �����������ֿ�����������һ���ն��豸 /dev/pts/2����ϣ�������Եĳ���ʹ������ն��豸��������������`(gdb) tty /dev/pts/2`
## ��ͣ�ָ���������
- ��GDB�У������¼��ַ�ʽ��ͣ���ϵ㡢�۲�㡢��׽�㡢�źš��߳�ֹͣ�����Ҫ�ָ��������У�ʹ��`c`����`continue`���
## ���öϵ�
- `break function`,�ڽ���ָ������ʱͣס��C++�п���ʹ��class::function����function(type, type)��ʽָ����������
- `break line`ָ���к�ͣס��
- `break +offset`��`break -offset`���ڵ�ǰִ��λ��֮�����֮ǰ�ļ���ָ�����һ���ϵ㡣
- `break filename:linenum`��Դ�ļ�filename��linenum��ͣס��
- `break filename:function`��Դ�ļ�filename��Function��������ڴ�ͣס��
- `break *address`�ڳ������е��ڴ��ַ��ͣס��
- `break`û�в�����ʾ����һ��ָ�ͣס��
- `break ... if condition`����������ʱͣס������ѭ�������У�`break if i == 100`��ʾiΪ100ʱͣס��
## �鿴�ϵ�
- `i[nfo] b[reakpoints] [n]`�鿴�ϵ���Ϣ�������ű�ʾ���Բ�д��n��ʾ�ϵ�ţ���д��ʾ�鿴���жϵ㡣

![alt text](image-2.png)

## ���ù۲��
- �۲��һ�������۲�ĳ�����ʽ������Ҳ��һ�ֱ��ʽ����ֵ�Ƿ��б仯�ˣ�����б仯��������ͣס��
- `watch expr`Ϊ���ʽexpr����һ���۲�㣬һ�����ʽ�б仯ʱ������ͣס����
- `rwatch expr`�����ʽ����expr����ȡʱ��ͣס����
- `awatch expr`�����ʽ����������ֵ�������߱�дʱ��ͣס����
- `info watchpoints`�г����������˵Ĺ۲�㡣
- ʹ�ò��Գ���`watch.cpp`����������`g++ -g -o watch watch.cpp`

![alt text](image-8.png)

- ��ɾ��watch�ϵ�2�����rwatch�ϵ㣬������x��һ�α���ȡʱ��������ִͣ�в�����GDB

![alt text](image-4.png)

- ��ɾ��rwatch�ϵ㣬���awatch�ϵ㣬������x��һ�α���ȡ��д��ʱ��������ִͣ�в�����GDB��

![alt text](image-5.png)

- �鿴�۲����Ϣ��

![alt text](image-6.png)

## ���ò�׽��
- ���ò�׽������׽��������ʱ��һЩ�¼��������빲��⡢C++�쳣��
```bash
$gcc -g  catch.c -o catch
#gcc -g  child.c -o child
$ gdb catch
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from catch...
(gdb) set follow-fork-mode child
(gdb) catch exec
Catchpoint 1 (exec)
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/catch 
[Attaching after process 1409038 fork to child process 1409042]
[New inferior 2 (process 1409042)]
[Detaching after fork from parent process 1409038]
[Inferior 1 (process 1409038) detached]
process 1409042 is executing new program: /home/aaa/bbb/ccc/GDBDebug/test1/child
[Switching to process 1409042]

Thread 2.1 "child" hit Catchpoint 1 (exec'd /home/aaa/bbb/ccc/GDBDebug/test1/child), 0x00007ffff7fd0100 in _start () from /lib64/ld-linux-x86-64.so.2
(gdb) b main
Breakpoint 2 at 0x555555555149: file child.c, line 7.
(gdb) l
1       #include <stdlib.h>
2       #include <stdio.h>
3       #include <unistd.h>
4
5       int my_print();
6       int main()
7       {
8           my_print();
9           return 0;
10      }
(gdb) b my_print 
Breakpoint 3 at 0x555555555162: file child.c, line 13.
(gdb) c
Continuing.

Thread 2.1 "child" hit Breakpoint 2, main () at child.c:7
7       {
(gdb) l
2       #include <stdio.h>
3       #include <unistd.h>
4
5       int my_print();
6       int main()
7       {
8           my_print();
9           return 0;
10      }
11
(gdb) s
8           my_print();
(gdb) n

Thread 2.1 "child" hit Breakpoint 3, my_print () at child.c:13
13      {
(gdb) n
14          printf("hello world\n");
(gdb) n
hello world
15          return 0;
(gdb) n
16      }
(gdb) 
main () at child.c:9
9           return 0;
(gdb) 
10      }
(gdb) 
__libc_start_main (main=0x555555555149 <main>, argc=1, argv=0x7fffffffdd48, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffdd38) at ../csu/libc-start.c:342
342     ../csu/libc-start.c: No such file or directory.
(gdb) 
[Inferior 2 (process 1409042) exited normally]
```
- ����������У�����Ҫ�Ĳ���ʱcatch exec����¼�������exec����¼�֮�������ӽ��̵ĳ����д�һ���ϵ㣬Ȼ��ִ��continue���������Կ�������ʱ����ͻ���뵽exec���õ��ӽ������ˡ�

��زο���
https://blog.csdn.net/www_dong/article/details/117304481

- `catch throw`����C++�׳����쳣
- `catch exec`����ϵͳ����execʱ
- `catch fork`����ϵͳ����fork
- `catch vfork`ϵͳ����vforkʱ
- `catch load`���빲���ʱ
- `catch unload`ж�ع����ʱ
- `tcatch <event>`ֵ����һ�β�׽�㣬������ͣס�Ժ�Ӧ���Զ�ɾ��

## ά��ֹͣ��

����������ֹͣ�㣬�����Ҫȡ��ֹͣ�㣬����ʹ��`delete`��`clear`��`disable`��`enable`�⼸������������ά��
- `clear`��������Ѿ������ֹͣ��
- `clear <function>`��`clear <filename:function>`���ָ�������ϵ�ֹͣ��
- `clear <linenum>`��`clear <filename:linenum>`���ָ�����ϵ�ֹͣ��
- `delete [breakpoints] [range...]`ɾ��ָ���Ķϵ㣬�����ָ���ϵ㣬���ʾɾ�����еĶϵ㣬range��ʾɾ���ϵ�ķ�Χ������1-4
- `disable [breakpoints] [range...]`disable��ָ����ֹͣ�㣬breakpointsΪֹͣ�㣬�����ָ������ʾdisable���е�ֹͣ�㣬��дdis
- `enable [breakpoints] [rangs...]`enable��ʾ����ָ����ֹͣ��
- `enable [breakpoints] once range...`enableָ����ֹͣ��һ�Σ�������ֹͣ�󣬸�ֹͣ���Զ�disable
- `enable [breakpoints] delete ragne...`enable��ָ����ֹͣ��һ�Σ�������ֹͣ���Զ�ɾ��

## ֹͣ����ά��

ֻ��break��watch����֧�����������ϵ㡣
- `condition <bnum> <expression>`�޸Ķϵ��Ϊbnum��ֹͣ����Ϊexpression
- `condition <bnum>`����ϵ��Ϊbnum��ֹͣ����
- `ignore <bnum> <count>`��������ʱ������ĳ���ϵ�count��

## Ϊ�ϵ��趨��������

�ڶϵ�ͣסʱ��������������һЩ������
- `command [bnum] ... command-list... end`Ϊ�ϵ�ָ��һ�������б��������ڶϵ�ͣסʱ�������б�������������α�����

ʹ�����³��������в��ԣ�
```C++
// command.cpp
#include <iostream>

void foo(int x)
{
    std::cout << "x = " << x << std::endl;
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        foo(i);
    }
    return 0;
}

```

�����ڵ���ϣ��ÿ�ε���`foo`����ʱ������ӡ����`x`��ֵ��Ȼ�����ִ�г���
����```g++ command.cpp -o command -g```�����Թ������£�
```bash
gdb command
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from command...
(gdb) b foo(int) 
Breakpoint 1 at 0x11c9: file command.cpp, line 4.
(gdb) command 1
Type commands for breakpoint(s) 1, one per line.
End with a line saying just "end".
>p x
>c
>end
(gdb) r
Starting program: /home/xxxx/GDBDebug/test1/command 

Breakpoint 1, foo (x=21845) at command.cpp:4
4       {
$1 = 21845
x = 0

Breakpoint 1, foo (x=0) at command.cpp:4
4       {
$2 = 0
x = 1

Breakpoint 1, foo (x=1) at command.cpp:4
4       {
$3 = 1
x = 2

Breakpoint 1, foo (x=2) at command.cpp:4
4       {
$4 = 2
x = 3

Breakpoint 1, foo (x=3) at command.cpp:4
4       {
--Type <RET> for more, q to quit, c to continue without paging--
$5 = 3
x = 4
[Inferior 1 (process 2436410) exited normally]
```

```bash
(gdb) b foo(int) if x > 0
Breakpoint 3 at 0x5555555551c9: file command.cpp, line 4.
(gdb) commands
Type commands for breakpoint(s) 3, one per line.
End with a line saying just "end".
>printf "x is %d\n", x
>c
>end
(gdb) r
Starting program: /home/xxx/GDBDebug/test1/command 

Breakpoint 3, foo (x=21845) at command.cpp:4
4       {
x is 21845
x = 0
x = 1

Breakpoint 3, foo (x=1) at command.cpp:4
4       {
x is 1
x = 2

Breakpoint 3, foo (x=2) at command.cpp:4
4       {
x is 2
x = 3

Breakpoint 3, foo (x=3) at command.cpp:4
4       {
x is 3
x = 4
[Inferior 1 (process 2441936) exited normally]
```

- ���Ҫ����ϵ��ϵ����ָ��`commands`��Ȼ�������`end`����

## �ָ��������к͵�������
- `continue`�������ִ�г���ֱ����������������һ���ϵ�
- `step <count>`����ִ�У�����к�������뺯�������뺯����ǰ���Ǹú�������debug��Ϣ
- `next <count>`�������ԣ�������뺯��
- `set step-mode on / off`����������ʱ�������Խ��뵽�⺯���ĵ����У�����ԭ���ݲ���ϸ������������

- ��ʹ�õĴ���
```
// step_mode.c
#include <stdio.h>

void customFunction()
{
    printf("Inside customFunction\n");
}

int main()
{
    printf("Hello, World!\n");
    customFunction();
    return 0;
}
```
- ��������```gcc -g step_mode.c -o step_mode -o0```��ִ�й������£�

```bash
(gdb) b main
Breakpoint 1 at 0x1160: file step_mode.c, line 9.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/step_mode 

Breakpoint 1, main () at step_mode.c:9
9       {
(gdb) set stemp-mode on
No symbol "stemp" in current context.
(gdb) set step-mode on
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/step_mode 

Breakpoint 1, main () at step_mode.c:9
9       {
(gdb) s
10          printf("Hello, World!\n");
(gdb) s
__GI__IO_puts (str=0x55555555601a "Hello, World!") at ioputs.c:33
33      ioputs.c: No such file or directory.
(gdb) finish
Run till exit from #0  __GI__IO_puts (str=0x55555555601a "Hello, World!") at ioputs.c:33
Hello, World!
main () at step_mode.c:11
11          customFunction();
Value returned is $1 = 14
(gdb) s
customFunction () at step_mode.c:4
4       {
(gdb) 
5           printf("Inside customFunction\n");
(gdb) 
__GI__IO_puts (str=0x555555556004 "Inside customFunction") at ioputs.c:33
33      ioputs.c: No such file or directory.
(gdb) finish
Run till exit from #0  __GI__IO_puts (str=0x555555556004 "Inside customFunction") at ioputs.c:33
Inside customFunction
customFunction () at step_mode.c:6
6       }
Value returned is $2 = 22
(gdb) s
main () at step_mode.c:12
12          return 0;
(gdb) s
13      }
(gdb) 
__libc_start_main (main=0x555555555160 <main>, argc=1, argv=0x7fffffffdd18, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffdd08) at ../csu/libc-start.c:342
342     ../csu/libc-start.c: No such file or directory.
(gdb) 
__GI_exit (status=0) at exit.c:138
138     exit.c: No such file or directory.
(gdb) 
139     in exit.c
(gdb) finish
warning: Function __GI_exit does not return normally.
Try to finish anyway? (y or n) y
Run till exit from #0  __GI_exit (status=0) at exit.c:139
[Inferior 1 (process 4103097) exited normally]
```
- `finish`���������ڵ��Թ������������е���ǰ������ĩβ�������ص��øú����ĵط������ڵ��Կ⺯����ʱ�����еĺ���ʱ�ر����ã����Կ����˳��������鿴����ֵ�͵�����

- ����ʹ�������`step_mode.c`���룬ִ�й������£�

```bash
(gdb) b main
Breakpoint 1 at 0x1160: file step_mode.c, line 9.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/step_mode 

Breakpoint 1, main () at step_mode.c:9
9       {
(gdb) b cus
cuserid         cuserid.c       customFunction  
(gdb) b customFunction   ## customFunction ���ϵ�
Breakpoint 2 at 0x555555555149: file step_mode.c, line 4.
(gdb) c   ## ���е��ϵ㴦
Continuing.
Hello, World!

Breakpoint 2, customFunction () at step_mode.c:4
4       {
(gdb) s  ## ���뵽�ϵ�
5           printf("Inside customFunction\n");
(gdb) finish  ## ִ��finish
Run till exit from #0  customFunction () at step_mode.c:5
Inside customFunction
main () at step_mode.c:12
12          return 0;
(gdb) n
13      }
(gdb) 
__libc_start_main (main=0x555555555160 <main>, argc=1, argv=0x7fffffffdd18, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffdd08) at ../csu/libc-start.c:342
342     ../csu/libc-start.c: No such file or directory.
(gdb) 
[Inferior 1 (process 4123010) exited normally]
(gdb) 
The program is not being run.
```

- `until`���ڼ���ִ�г���ֱ����ǰ������ѭ���Ľ��������ڵ���ѭ�����ʱ�����еĺ���ʱ�ر����ã����Կ�������ʣ���ѭ�������������룬ֱ�ӵ���ѭ�������Ľ�����
- ʾ�����룺
```C++
// until.c
#include <stdio.h>

void customFunction() {
    for (int i = 0; i < 5; i++) {
        printf("Loop iteration %d\n", i);
    }
    printf("End of customFunction\n");
}

int main() {
    printf("Hello, World!\n");
    customFunction();
    return 0;
}
```
- ���Թ������£�
```bash
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/until 

Breakpoint 1, main () at until.c:13
13      {
(gdb) n
14          printf("Hello, World!\n");
(gdb) n
Hello, World!
15          customFunction();
(gdb) s
customFunction () at until.c:4
4       {
(gdb) 
5           for (int i = 0; i < 5; i++)
(gdb) 
7               printf("Loop iteration %d\n", i);
(gdb) until
Loop iteration 0
5           for (int i = 0; i < 5; i++)
(gdb) until
Loop iteration 1
Loop iteration 2
Loop iteration 3
Loop iteration 4
9           printf("End of customFunction\n");
```

- `stepi`��`si`��`nexti`��`ni`���ڵ���ִ�г���Ļ��ָ�������Դ�����С�
- ʹ�õ��Դ������£�
```C++
// compilation.c
#include <stdio.h>
int main()
{
    int a = 5;
    int b = 10;
    int c = a + b;
    printf("Sum: %d\n", c);
    return 0;
}
```
- ���Թ������£�
```bash
(gdb) b main
Breakpoint 1 at 0x1149: file compilation.c, line 4.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/compilation 

Breakpoint 1, main () at compilation.c:4
4       {
(gdb) layout asm
```
![alt text](image-7.png)

## �ź�
- `handle`��������ָ�� GDB �ڽ��յ��ض��ź�ʱӦ��ȡ�Ķ������ź��ǲ���ϵͳ����̷��͵��첽֪ͨ������֪ͨĳЩ�¼��ķ��������������󡢷Ƿ��ڴ���ʵȡ�ʹ�� handle �������Ը��� GDB ��δ�����Щ�źţ��Ǽ�������ִ�С�ֹͣ�����Ǻ����źš�
- `handle`��������﷨��
```
handle signal [keywords...]
```
- signal ��Ҫ������ź����ƻ��߱��
- `keywords`��GDBӦ�ö��ź�ִ�еĲ���������������һ�������ؼ��ֵ���ϣ�
- nostop�������յ����ź�ʱ����������ִ�У���ͣ����
- stop�������յ����ź�ʱ��ֹͣ����ִ��
- nopass�������յ����ź�ʱ�����������ݸ�����
- pass�������յ����ź�ʱ���������ݸ�����
- print�������յ����ź�ʱ����ӡ֪ͨ��Ϣ
- noprint�������յ����ź�ʱ������ӡ֪ͨ��Ϣ

```C++
// signal.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// �źŴ�����
void signal_handler(int signum)
{
    printf("Received signal: %d\n", signum);
    // �������źŴ���������һЩ�������¼��־���߽����ض�����
}

int main()
{
    // ע���źŴ�����
    signal(SIGINT, signal_handler);  // ���յ� SIGINT (Ctrl+C) ʱ���� signal_handler
    signal(SIGSEGV, signal_handler); // ���յ� SIGSEGV (�δ���) ʱ���� signal_handler

    // ����ѭ����ģ���������
    while (1)
    {
        printf("Program running...\n");
        sleep(1);
    }

    return 0;
}
```

```bash
(gdb) b main
Breakpoint 1 at 0x11d1: file signal.c, line 14.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/signal 

Breakpoint 1, main () at signal.c:14
14      {
(gdb) handle SIGINT stop print  ## ���ô�����
SIGINT is used by the debugger.
Are you sure you want to change it? (y or n) y
Signal        Stop      Print   Pass to program Description
SIGINT        Yes       Yes     No              Interrupt
(gdb) handle SIGSEGV stop print  ## ���ô�����
Signal        Stop      Print   Pass to program Description
SIGSEGV       Yes       Yes     Yes             Segmentation fault
(gdb) c
Continuing.
Program running...
Program running...
Program running...
Program running...
Program running...
Program running...
^C
Program received signal SIGINT, Interrupt.
0x00007ffff7e931b4 in __GI___clock_nanosleep (clock_id=<optimized out>, clock_id@entry=0, flags=flags@entry=0, req=req@entry=0x7fffffffdbf0, rem=rem@entry=0x7fffffffdbf0) at ../sysdeps/unix/sysv/linux/clock_nanosleep.c:78
78      ../sysdeps/unix/sysv/linux/clock_nanosleep.c: No such file or directory.
```

- `info signals`�鿴�ź�
```bash
info signals
Signal        Stop      Print   Pass to program Description

SIGHUP        Yes       Yes     Yes             Hangup
SIGINT        Yes       Yes     No              Interrupt
SIGQUIT       Yes       Yes     Yes             Quit
SIGILL        Yes       Yes     Yes             Illegal instruction
SIGTRAP       Yes       Yes     No              Trace/breakpoint trap
SIGABRT       Yes       Yes     Yes             Aborted
SIGEMT        Yes       Yes     Yes             Emulation trap
SIGFPE        Yes       Yes     Yes             Arithmetic exception
SIGKILL       Yes       Yes     Yes             Killed
SIGBUS        Yes       Yes     Yes             Bus error
SIGSEGV       Yes       Yes     Yes             Segmentation fault
SIGSYS        Yes       Yes     Yes             Bad system call
SIGPIPE       Yes       Yes     Yes             Broken pipe
SIGALRM       No        No      Yes             Alarm clock
SIGTERM       Yes       Yes     Yes             Terminated
SIGURG        No        No      Yes             Urgent I/O condition
SIGSTOP       Yes       Yes     Yes             Stopped (signal)
SIGTSTP       Yes       Yes     Yes             Stopped (user)
SIGCONT       Yes       Yes     Yes             Continued
SIGCHLD       No        No      Yes             Child status changed
SIGTTIN       Yes       Yes     Yes             Stopped (tty input)
SIGTTOU       Yes       Yes     Yes             Stopped (tty output)
SIGIO         No        No      Yes             I/O possible
SIGXCPU       Yes       Yes     Yes             CPU time limit exceeded
SIGXFSZ       Yes       Yes     Yes             File size limit exceeded
SIGVTALRM     No        No      Yes             Virtual timer expired
SIGPROF       No        No      Yes             Profiling timer expired
```

- `info handle`�鿴��Щ�ź���GDB�б����
```bash
info handle
Signal        Stop      Print   Pass to program Description

SIGHUP        Yes       Yes     Yes             Hangup
SIGINT        Yes       Yes     No              Interrupt
SIGQUIT       Yes       Yes     Yes             Quit
SIGILL        Yes       Yes     Yes             Illegal instruction
SIGTRAP       Yes       Yes     No              Trace/breakpoint trap
SIGABRT       Yes       Yes     Yes             Aborted
SIGEMT        Yes       Yes     Yes             Emulation trap
SIGFPE        Yes       Yes     Yes             Arithmetic exception
SIGKILL       Yes       Yes     Yes             Killed
SIGBUS        Yes       Yes     Yes             Bus error
SIGSEGV       Yes       Yes     Yes             Segmentation fault
SIGSYS        Yes       Yes     Yes             Bad system call
SIGPIPE       Yes       Yes     Yes             Broken pipe
SIGALRM       No        No      Yes             Alarm clock
SIGTERM       Yes       Yes     Yes             Terminated
SIGURG        No        No      Yes             Urgent I/O condition
SIGSTOP       Yes       Yes     Yes             Stopped (signal)
SIGTSTP       Yes       Yes     Yes             Stopped (user)
SIGCONT       Yes       Yes     Yes             Continued
SIGCHLD       No        No      Yes             Child status changed
SIGTTIN       Yes       Yes     Yes             Stopped (tty input)
SIGTTOU       Yes       Yes     Yes             Stopped (tty output)
SIGIO         No        No      Yes             I/O possible
SIGXCPU       Yes       Yes     Yes             CPU time limit exceeded
SIGXFSZ       Yes       Yes     Yes             File size limit exceeded
SIGVTALRM     No        No      Yes             Virtual timer expired
SIGPROF       No        No      Yes             Profiling timer expired
```

## �߳�

- `break <linespec> thread <threadno>`
- `break <linespec> thread <threadno> if ...`
- `info threads`�鿴�߳���Ϣ
- ʹ�ó���
```C++
// thread_test.cpp
#include <iostream>
#include <thread>
#include <chrono>

void task1()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Task 1 running... " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void task2()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Task 2 running... " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main()
{
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
```
- ���н��������ʾ��
```bash
(gdb) b task1
Breakpoint 1 at 0x1309
(gdb) b task2
Breakpoint 2 at 0x13ac
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/thread 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[New Thread 0x7ffff7a41700 (LWP 61886)]
[New Thread 0x7ffff7240700 (LWP 61887)]
[Switching to Thread 0x7ffff7a41700 (LWP 61886)]

Thread 2 "thread" hit Breakpoint 1, 0x0000555555555309 in task1() ()
(gdb) info threads
  Id   Target Id                                  Frame 
  1    Thread 0x7ffff7a42740 (LWP 61872) "thread" __pthread_clockjoin_ex (threadid=140737348114176, thread_return=0x0, clockid=<optimized out>, abstime=<optimized out>, block=<optimized out>) at pthread_join_common.c:145
* 2    Thread 0x7ffff7a41700 (LWP 61886) "thread" 0x0000555555555309 in task1() ()
  3    Thread 0x7ffff7240700 (LWP 61887) "thread" 0x00005555555553ac in task2() ()
(gdb) b thread.cpp:7 thread 2
No source file named thread.cpp.
Make breakpoint pending on future shared library load? (y or [n]) n
(gdb) b ./thread.cpp:7 thread 2
No source file named ./thread.cpp.
Make breakpoint pending on future shared library load? (y or [n]) n
(gdb) pwd
```

## �鿴ջ��Ϣ

- `backtrace`����`bt`
- `backtrace <n>`��ʾֻ��ӡջ����n��ջ��Ϣ
- `backtrace <-n>`��ʾֻ��ӡջ�ײ��n����Ϣ
- �л�ջ������ֹͣʱ�����ջ���ǵ�ǰջ��ʹ��`frame <n>`�����л�
- `up <n>`��ʾ��ջ�������ƶ�n�㣬��дn��ʾ1��
- `down <n>`��ʾ��ջ�������ƶ�n�㣬��дn��ʾ1��

```bash
(gdb) bt
#0  0x0000555555555309 in task1() ()
#1  0x0000555555556276 in void std::__invoke_impl<void, void (*)()>(std::__invoke_other, void (*&&)()) ()
#2  0x000055555555620e in std::__invoke_result<void (*)()>::type std::__invoke<void (*)()>(void (*&&)()) ()
#3  0x00005555555561a0 in void std::thread::_Invoker<std::tuple<void (*)()> >::_M_invoke<0ul>(std::_Index_tuple<0ul>) ()
#4  0x000055555555615d in std::thread::_Invoker<std::tuple<void (*)()> >::operator()() ()
#5  0x000055555555612e in std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)()> > >::_M_run() ()
#6  0x00007ffff7e79df4 in ?? () from /lib/x86_64-linux-gnu/libstdc++.so.6
#7  0x00007ffff7f8d609 in start_thread (arg=<optimized out>) at pthread_create.c:477
#8  0x00007ffff7cb5353 in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95
(gdb) f  ## ��ʾ��ǰջ
#0  0x0000555555555309 in task1() ()
(gdb) info f  ## �鿴��ǰջ��Ϣ
Stack level 0, frame at 0x7ffff7a40e20:
 rip = 0x555555555309 in task1(); saved rip = 0x555555556276
 called by frame at 0x7ffff7a40e40
 Arglist at 0x7ffff7a40e10, args: 
 Locals at 0x7ffff7a40e10, Previous frame's sp is 0x7ffff7a40e20
 Saved registers:
  rip at 0x7ffff7a40e18
```

- `info args`��ӡ��ǰ�����Ĳ���������ֵ
- `info locals`��ӡ��ǰ�����ľֲ�������ֵ
- `info catch`��ӡ�����е��쳣������Ϣ

## ��ʾԴ����

- ����ʱ����`-g`ѡ��ſ��Բ鿴Դ���룬��GDBͣ��ʱ���ᱨ�����ĸ��ļ��ĵڼ�����
- `list <linenum>`��ʾlinenum��Χ��Դ����
- `list <function>`��ʾ������Ϊfunction�ĺ�����Դ����
- `list`����`l`��ʾ��ǰ�к����Դ����
- `list -`��ʾ��ǰ��ǰ���Դ����
- `set listsize <count>`����һ����ʾԴ���������
- `show listsize`�鿴��ǰlistsize������
- `list <first>, <last>`��ʾ��first�е�last��֮���Դ����
- `list , <last>`��ʾ�ӵ�ǰ�е�last��֮���Դ����
- `list +`������ʾԴ���룬һ�������list��������²�����
- `<linenum>`�к�
- `<+offset>`��ǰ�кŵ���ƫ����
- `<-offset>`��ǰ�кŵĸ�ƫ����
- `<filename:linenum>`�ĸ��ļ�����һ��
- `<function>`������
- `<filename:function>`�ĸ��ļ��е��ĸ�����
- `<*address>`��������ʱ��������ڴ��еĵ�ַ

## ����Դ����


- `forward-search <regexp>`��ǰ����
- `search <regexp>`�������
- `reverse-search <regexp>`��������
- ʹ��`thread_test.cpp`Դ����
```bash
(gdb) forward-search task
26          std::thread t2(task2);
(gdb) 
Expression not found
(gdb) 
Expression not found
(gdb) reverse-search task
25          std::thread t1(task1);
(gdb) 
14      void task2()
(gdb) 
5       void task1()
(gdb) 
Expression not found
(gdb) reverse-search task
Expression not found
(gdb) 
Expression not found
(gdb) search task
14      void task2()
(gdb) 
25          std::thread t1(task1);
(gdb) 
26          std::thread t2(task2);
(gdb) 
Expression not found
```

## ָ��Դ�ļ�·��

- `directory` ����������ӻ���� GDB ����Դ�ļ���Ŀ¼�б����������԰��� GDB �ڵ���ʱ�ҵ����Դ���룬�ر��ǵ�Դ���벻�ڵ�ǰ����Ŀ¼��ʱ��
- ʹ��ʾ��
```C++
// File: /home/aaa/bbb/ccc/GDBDebug/test1/src/directory.cpps
#include <iostream>

int main() {
    std::cout << "Hello, GDB!" << std::endl;
    return 0;
}
```
- ����ʱ�����ɵĿ�ִ���ļ�����test1�ļ����£�`g++ test1/src/directory.cpp -o test1/directory -g`����Դ�ļ�������һ���ļ�����
- ���Թ������£�
```bash
$ gdb test1/directory  ## ����Ҫ���Եĳ���
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/directory...
(gdb) directory /home/aaa/bbb/ccc/GDBDebug/test1/src/   ## ���Ŀ¼
Source directories searched: /home/aaa/bbb/ccc/GDBDebug/test1/src/:$cdir:$cwd
(gdb) b directory.cpp:5   ## ��Ӷϵ�
Breakpoint 1 at 0x11a9: file test1/src/directory.cpp, line 5.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/directory 

Breakpoint 1, main () at test1/src/directory.cpp:5  ## ������ȷ���ҵ�Դ�ļ�
5       {
(gdb) show directories  ## ��ʾĿ¼
Source directories searched: /home/aaa/bbb/ccc/GDBDebug/test1/src:$cdir:$cwd
```
- ��Ӷ��Ŀ¼ʱ��ʹ�ÿո������������ Windows ����Ӷ��Ŀ¼��������������Ŀ¼ C:\Projects\Source1 �� C:\Projects\Source2����ʹ��`(gdb) directory C:\\Projects\\Source1 C:\\Projects\\Source2`����`(gdb) directory C:/Projects/Source1 C:/Projects/Source2`���� Linux ����Ӷ��Ŀ¼��������������Ŀ¼ /home/user/projects/source1 �� /home/user/projects/source2��ʹ��`(gdb) directory /home/user/projects/source1 /home/user/projects/source2`

- ������е��Զ����Դ�ļ�����·����Ϣ`directory`
- ��ʾ�����˵�Դ�ļ�����·��`show directories`

## Դ������ڴ�

- `info line directory.cpp:main`�鿴main�����ĵ�ַ
- `info line`�������������кţ����������ļ������кţ��ļ�����������
- `disassemble func`�鿴����func�Ļ�����
- ִ�н�����£�
```bash
(gdb) info line directory.cpp:main
Line 5 of "test1/src/directory.cpp" starts at address 0x11a9 <main()> and ends at 0x11b1 <main()+8>.
(gdb) disassemble main
Dump of assembler code for function main():
   0x00000000000011a9 <+0>:     endbr64 
   0x00000000000011ad <+4>:     push   %rbp
   0x00000000000011ae <+5>:     mov    %rsp,%rbp
   0x00000000000011b1 <+8>:     lea    0xe4d(%rip),%rsi        # 0x2005
   0x00000000000011b8 <+15>:    lea    0x2e81(%rip),%rdi        # 0x4040 <_ZSt4cout@@GLIBCXX_3.4>
   0x00000000000011bf <+22>:    callq  0x1090 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x00000000000011c4 <+27>:    mov    %rax,%rdx
   0x00000000000011c7 <+30>:    mov    0x2e02(%rip),%rax        # 0x3fd0
   0x00000000000011ce <+37>:    mov    %rax,%rsi
   0x00000000000011d1 <+40>:    mov    %rdx,%rdi
   0x00000000000011d4 <+43>:    callq  0x10a0 <_ZNSolsEPFRSoS_E@plt>
   0x00000000000011d9 <+48>:    mov    $0x0,%eax
   0x00000000000011de <+53>:    pop    %rbp
   0x00000000000011df <+54>:    retq   
End of assembler dump.
```

## �鿴����ʱ����

-  `p[rint] <expr>`����`p[rint] /<f> <expr>`�����`<f>`ָ�������ʽ
- ��ӡ����ֵ`p val`
- ��ӡ���ʽ��ֵ`p val1 + val2`
- ��ӡָ���ֵ��ָ�������`p ptr`,`p *ptr`
- ��ӡ�ṹ���Ա`p struct_val.member`
- ��ӡ��������`p array`,`p array[0]@10`����ӡarray�ĵ�ַ��array��ǰ10��Ԫ��
- ��ӡ����`p object`
- ��ӡ�ڴ��ַ������`p *(char*)0x601050`
- ��ʽ�������
```bash
(gdb) print /x var   # ��ʮ�����Ƹ�ʽ���
(gdb) print /d var   # ��ʮ���Ƹ�ʽ���
(gdb) print /c var   # ���ַ���ʽ���
(gdb) print /s var   # ���ַ�����ʽ���
(gdb) print /t var   # ��������������ʾ
(gdb) print /u var   # ��ʮ��������ʾ�޷�������
(gdb) print /o var   # �˽�����ʾ����
(gdb) print /a var   # ʮ��������ʾ����
(gdb) print /f val   # ��������ʾ����
```
- ���Դ���
```C++
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

int main() {
    int a = 10;
    int b = 20;
    int *ptr = &a;
    Point p = {3, 4};
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::cout << "Hello, GDB!" << std::endl;
    return 0;
}
```
- ���н�����£�
```bash
$ gdb test1/print_test 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/print_test...
(gdb) b main
Breakpoint 1 at 0x1289: file test1/print_test.cpp, line 10.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/print_test 

Breakpoint 1, main () at test1/print_test.cpp:10
10      {
(gdb) p a
$1 = 1
(gdb) n
11          int a = 10;
(gdb) n
12          int b = 20;
(gdb) p a
$2 = 10
(gdb) b print_test.cpp:18
Breakpoint 2 at 0x555555555362: file test1/print_test.cpp, line 18.
(gdb) c
Continuing.
Hello, GDB!

Breakpoint 2, main () at test1/print_test.cpp:18
18          return 0;
(gdb) p b
$3 = 20
(gdb) p ptr
$4 = (int *) 0x7fffffffdb88
(gdb) p *ptr
$5 = 10
(gdb) p p
$6 = {x = 3, y = 4}
(gdb) p vec
$7 = std::vector of length 5, capacity 5 = {1, 2, 3, 4, 5}
(gdb) p vec[0]@5
$8 = {1, 2, 3, 4, 5}
(gdb) p /x a
$9 = 0xa
(gdb) p /d a
$10 = 10
(gdb) p vec@4
$11 = {std::vector of length 5, capacity 5 = {1, 2, 3, 4, 5}, std::vector of length -23454100575501, capacity -23451953091852 = {267633501, 1213594142, -2092374647, -1991765780, -1958152067, -1991706555, 18933959, -913309696, 267620547, 1213594142, -2092374647, -1991765780, 
    -1958152067, -1991706555, 17885383, -913309696, 267620547, 1213594142, 1213457801, 1211690115, 1222147465, -1991708535, -225883946, -1069184696, -933918392, -800224952, 76236900, 10277, 1166624768, 1220555240, 1222133131, 1221612939, -1991715191, 16050375, -1924661248, 
    -1991720891, 24832199, -1991770112, 1166887107, -947304256, 87528, -1047967744, -666531000, 1222281544, -1991717239, 26273991, 518717440, -98693133, 1220774216, 1222133131, -639055991, 1207959552, -1991714679, -58660665, -1958150145, 1214572613, 673514547, 1946157056, 
    -63117307, -2092367873, 1566259396, 267620547, 1213594142, -2092374647, -1991765780, -1958152067, -1991706555, 32303303, -1991770112, 1166756034, 1217087736, 1166755848, 9128184, 1221495112, -504838263, 1207959553, 1224230283, 1843971977, -1879048192, 267633609, 
    1213594142, -1991711351, 1569781885, 267620547, 1213594142, -1991711351, 1569781885, 267620547, 1213594142, -2092374647, -1991765780, -1958152067, -1991706555, -22484793, -913244161, 267620547, 1213594142, -2092374647, -1991765780, -1991706499, -1958154123, -1958152123, 
    -1991708587, -947304234, 104936, -1010200576, -98693133, -443987883, 283935560, -125990584, -129660088, 273713992, -129660088, 1207995208, -1991720407, -121550640, -1031190526, -129660088, 1208519496, 1224230283, -1991717239, 25880775, -1958215680, -1991706555, 
    -9901881, -913244161, 267620547, 1213594142, -1991711351, -1958152067, -1958152123, -1866244864, -98693133, -443987883, -326940589, 2106148888, 1166756072, -947304216, -12824, -1014413057, -398095544, -389576376, 370, 48283976, 1222115656, 1528349827, 267633501, 
    1213594142, 1213457801, 1211690115, 1222147465, 1221621129, 1221088649, 1221088651, 1221608843, -1991715191, 21948615, -1991770112, -1958156219, -1958160291, -1991714747, 7661767, -1991770112, 1166756034, -695645976, -389576376, 384, 1220970824, -68624503, 1207959553, 
    1222137227, -1958215031, -1958160315, 1435191296, -490649368, -1040103422, -666531000, 273713480, -666531000, -389576376, 42, 1220643144, 1222133131, -1958211445, -1958164363, -1991716795, 32237767, -1958215680, -1991714731, 1217398850, 1530446979, 267633501, 
    1213594142, -1991711351, -1958152067, -1017251771, -98693133, -443987883, 552371016, -125990584...}, std::vector of length 346103213422400382, capacity -35183298347009 = {<error reading variable>
(gdb) p vec[0]@4
$12 = {1, 2, 3, 4}
```

## ���ʽ

- `@`������Ҫ������ӡ��������ݣ�`(gdb) print array[0]@10`
- `::`������Ҫ���ڱ�ʶ C++ �����е���������ռ�������
- ������ľ�̬��Ա�����;�̬��Ա����
- ���Դ���
```C++
// region.cpp
#include <iostream>
using namespace std;

class MyClass
{
public:
    static int staticVar;
    static void staticFunc()
    {
        // some code
        std::cout << "Hello, GDB!" << std::endl;
    }
};

int MyClass::staticVar = 42;

int main()
{
    MyClass::staticFunc();
    return 0;
}
```

- ���Թ������£�
```bash
$ gdb test1/region 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/region...
(gdb) b region.cpp:29
Breakpoint 1 at 0x11e9: file test1/region.cpp, line 29.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/region 
Hello, GDB!

Breakpoint 1, main () at test1/region.cpp:29
29          return 0;
(gdb) p MyClass::staticVar  ## ͨ��������������еľ�̬����
$1 = 42
(gdb) p MyNamespace::var  ## ͨ����������������ռ��еı���
$2 = 5
(gdb) call MyClass::staticFunc()  ## ͨ��������������еľ�̬����
Hello, GDB!
(gdb) call MyNamespace::func()  ## ͨ����������������ռ��еĺ���
MyNamespace::func() called. Hello, GDB!
```

## �������

- ��GDB�У�������ʱ�鿴ȫ�ֱ����������ļ��ɼ�������̬ȫ�ֱ�������ǰ�ļ��ɼ��ģ����ֲ���������ǰ��Χ�ɼ��ģ�
- ���ȫ�ֱ����;ֲ�����������ͬ�������ʹ���������޶�����`file::var`,`func::var`

## ����

- ���Թ����У���Ҫ�鿴�����ڴ�ռ��ֵ�����Ƕ�̬�������ݵĴ�С������ʹ�����潲����`@`���ţ���߷ŵ�һ���ڴ��ַ���ұ߷���Ҫ�鿴���ڴ�ĳ��ȣ����磬���������`int * array = (int*)malloc(len * sizeof(int));`������ʹ������������в鿴��`p *array@len`������Ǿ�̬����Ļ�������ֱ��`p ������`

## �鿴�ڴ�

- `examine/<n><f><u> <addr>`�鿴�ڴ��е�ֵ��`examine`���Լ�дΪ`x`
- `n`��һ������������ʾ��ʾ�ڴ�ĳ��ȣ�Ҳ���Ǵӵ�ǰ��ַ�����ʾ������ַ������
- `<f>`����ʾ��ʽ����ʾ���ݵĸ�ʽ�������� x��ʮ�����ƣ���d��ʮ���ƣ���u���޷���ʮ���ƣ���o���˽��ƣ���t�������ƣ���f������������a����ַ����c���ַ����� s���ַ�������
- `<u>`����λ��С����ʾ�ڴ浥Ԫ�Ĵ�С�������� b���ֽڣ���h�����֣���w���֣��� g�����֣��� 8 �ֽڣ���
- `<address>`��Ҫ�����ڴ��ַ
- ��ʾ�����ֽڵ�ʮ������ֵ��`x/1xb <address>`
- ��ʾ�ĸ��ֽڵ�ʮ������ֵ��`x/4xw <address>`
- ��ʾ�ĸ��ֽڵ�ʮ����ֵ��`x/4dw <address>`
- ��ʾ�ڴ��е��ַ�����`x/s <address>`
- ��ʾʮ���޷���ʮ��������`x/10uw <address>`
- ���Գ������£�
```C++
// examine.cpp
#include <iostream>

int main()
{
    int numbers[4] = {10, 20, 30, 40};
    char message[] = "Hello, GDB!";
    std::cout << "Debugging example" << std::endl;
    return 0;
}
```
- ���Թ������£�
```bash
$ gdb test1/examine 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/examine...
(gdb) b main
Breakpoint 1 at 0x11c9: file test1/examine.cpp, line 4.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/examine 

Breakpoint 1, main () at test1/examine.cpp:4
4       {
(gdb) p numbers  ## δ���е��ó�ʼ������ʱ��Ϊ��ֵ
$1 = {-136555800, 32767, 1431655104, 21845}
(gdb) n
5           int numbers[4] = {10, 20, 30, 40};
(gdb) n
6           char message[] = "Hello, GDB!";
(gdb) p numbers   ## ��ʼ��֮���ֵ
$2 = {10, 20, 30, 40}
(gdb) p &numbers  ## ��ӡ��ַ
$3 = (int (*)[4]) 0x7fffffffdbd0
(gdb) x/4dw 0x7fffffffdbd0 ## ���ĵ�ַ����Ϊ4��ʮ��������ÿ����ֵΪһ��w���֣�
0x7fffffffdbd0: 10      20      30      40
(gdb) n
7           std::cout << "Debugging example" << std::endl;
(gdb) p &message 
$4 = (char (*)[12]) 0x7fffffffdbec
(gdb) x/s 0xfffffffdbec  ## ���õ�ַ���Ϊһ���ַ���
0xfffffffdbec:  <error: Cannot access memory at address 0xfffffffdbec>
(gdb) x/s 0x7fffffffdbec  ## ���õ�ַ���Ϊһ���ַ���
0x7fffffffdbec: "Hello, GDB!" 
(gdb) x/16xb 0x7fffffffdbd0  ## ���õ�ַ���Ϊ16��16���Ƶ�����ÿ����һ���ֽڣ�Ҳ����ÿ���ֽ����Ϊһ��ʮ������
0x7fffffffdbd0: 0x0a    0x00    0x00    0x00    0x14    0x00    0x00    0x00
0x7fffffffdbd8: 0x1e    0x00    0x00    0x00    0x28    0x00    0x00    0x00
(gdb) x/12cb 0x7fffffffdbec  ## ��ʾ message ��ÿ���ַ�
0x7fffffffdbec: 72 'H'  101 'e' 108 'l' 108 'l' 111 'o' 44 ','  32 ' '  71 'G'
0x7fffffffdbf4: 68 'D'  66 'B'  33 '!'  0 '\000'
```

## �Զ���ʾ

- `display`���������ڳ��������ڼ��Զ���ʾ���ʽ��ֵ��ÿ�γ���ֹͣʱ��GDB ���Զ���ʾָ�����ʽ�ĵ�ǰֵ�����ڵ���ʱ�ǳ�����
- �����Զ���ʾ`display <expression>`
- �鿴�����Զ���ʾ�ı��ʽ`info display`
- ɾ���Զ���ʾ�ı��ʽ`undisplay <display-number>`
- �����Զ���ʾ`disable display <display-number>`
- �����Զ���ʾ`enable display <display-number>`
- ��������Զ���ʾ�ı��ʽ`delete display`
- ʹ�ò��Դ��룺
```C++
// display.cpp
#include <iostream>

int main()
{
    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        std::cout << "i = " << i << std::endl;
    }
    float f = 3.14;
    char c = 'A';
    const char *str = "Hello, GDB!";
    int arr[] = {1, 2, 3, 4, 5};
    return 0;
}
```
- ���Թ������£�
```bash
$ gdb test1/display 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/display...
(gdb) b display.cpp:6
Breakpoint 1 at 0x120b: file test1/display.cpp, line 6.
(gdb) b display.cpp:14
Breakpoint 2 at 0x1295: file test1/display.cpp, line 14.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/display 

Breakpoint 1, main () at test1/display.cpp:6
6           for (i = 0; i < 5; ++i)
(gdb) display i
1: i = 0
(gdb) display /f f
2: /f f = 4.59163468e-41
(gdb) display /c c
3: /c c = 0 '\000'
(gdb) display /s str
4: x/s str  0x555555555320 <__libc_csu_init>:   "\363\017\036\372AWL\215=;*"
(gdb) display /x arr
5: /x arr = {0x0, 0x0, 0x55555100, 0x5555, 0xffffdcf0}
(gdb) display /d arr[0]
6: /d arr[0] = 0
(gdb) info display
Auto-display expressions now in effect:
Num Enb Expression
1:   y  i
2:   y  /f f
3:   y  /c c
4:   y  /1bs str
5:   y  /x arr
6:   y  /d arr[0]
(gdb) c
Continuing.
i = 0
i = 1
i = 2
i = 3
i = 4

Breakpoint 2, main () at test1/display.cpp:14
14          return 0;
1: i = 5
2: /f f = 3.1400001
3: /c c = 65 'A'
4: x/s str  0x55555555600a:     "Hello, GDB!"
5: /x arr = {0x1, 0x2, 0x3, 0x4, 0x5}
6: /d arr[0] = 1
(gdb) disable display 1
(gdb) b display.cpp:15
Breakpoint 3 at 0x55555555529a: display.cpp:15. (3 locations)
(gdb) n

Breakpoint 3, main () at test1/display.cpp:15
15      }
2: /f f = 3.1400001
3: /c c = 65 'A'
4: x/s str  0x55555555600a:     "Hello, GDB!"
5: /x arr = {0x1, 0x2, 0x3, 0x4, 0x5}
6: /d arr[0] = 1
```
- `display /i $pc`������ʾ�����������ǰָ��Ļ��ָ��
- ���Դ������£�
```C++
// display1.cpp
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int c = a + b;
    printf("Sum: %d\n", c);
    return 0;
}
```
- ���Թ������£�
```bash
$ gdb test1/display1 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/display1...
(gdb) display /i $pc
1: x/i $pc
<error: No registers.>
(gdb) b main
Breakpoint 1 at 0x1149: file test1/display1.cpp, line 4.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/display1 

Breakpoint 1, main () at test1/display1.cpp:4
4       {
1: x/i $pc
=> 0x555555555149 <main()>:     endbr64 
(gdb) n
5           int a = 5;
1: x/i $pc
=> 0x555555555155 <main()+12>:  movl   $0x5,-0xc(%rbp)
(gdb) 
6           int b = 10;
1: x/i $pc
=> 0x55555555515c <main()+19>:  movl   $0xa,-0x8(%rbp)
(gdb) 
7           int c = a + b;
1: x/i $pc
=> 0x555555555163 <main()+26>:  mov    -0xc(%rbp),%edx
(gdb) 
8           printf("Sum: %d\n", c);
1: x/i $pc
=> 0x55555555516e <main()+37>:  mov    -0x4(%rbp),%eax
(gdb) 
Sum: 15
9           return 0;
1: x/i $pc
=> 0x555555555184 <main()+59>:  mov    $0x0,%eax
(gdb) 
10      }
1: x/i $pc
=> 0x555555555189 <main()+64>:  leaveq 
(gdb) 
__libc_start_main (main=0x555555555149 <main()>, argc=1, argv=0x7fffffffdcf8, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffdce8) at ../csu/libc-start.c:342
342     ../csu/libc-start.c: No such file or directory.
1: x/i $pc
=> 0x7ffff7dda083 <__libc_start_main+243>:      mov    %eax,%edi
(gdb) 
[Inferior 1 (process 3316307) exited normally]
```

## ������ʾѡ��

- `set print address on/off`��/�رյ�ַ�������������ʾ����ʱ��GDB���Գ������Ĳ�����ַ��Ĭ�ϴ�
- `show print address`�鿴��ǰ��ַ��ʾѡ���Ƿ��
- `set print array on/off`��/�ر�������ʾ��������ʾ����һ������ʾ��Ĭ�Ϲر�
- `show print array`�鿴������ʾ�Ƿ��
- `set print elements <number-of-elements>`������ʾ�������󳤶�
- `show print elements`��Ĭ��200
- `set print null-stop <on/off>`�򿪱�ʾ��ʾ�ַ���ʱ��������������ֹͣ��ʾ��Ĭ��off
- `set print pretty on`��ʽ����ʾ�ṹ�壬Ĭ�Ϲرգ�һ������ʾ�ṹ��
- `set print sevenbit-strings <on/off>`�Ƿ�`\nnn`��ʽ��ʾ�ַ����ַ�����Ĭ�Ϲر�
- `set print union <on/off>`������ʾ�ṹ��ʱ���Ƿ���ʾ���ڲ�������������
- ���Դ������£�
```C++
#include <stdio.h>

typedef union
{
    int i;
    float f;
    char str[20];
} Data;

typedef enum
{
    Tree,
    Bug
} Species;
typedef enum
{
    Big_tree,
    Acorn,
    Seedling
} Tree_forms;
typedef enum
{
    Caterpillar,
    Cocoon,
    Butterfly
} Bug_forms;
struct thing
{
    Species it;
    union
    {
        Tree_forms tree;
        Bug_forms bug;
    } form;
};

int main()
{
    Data data;
    data.i = 10;
    printf("data.i = %d\n", data.i);
    printf("data.f = %f\n", data.f);
    printf("data.str = %s\n", data.str);

    struct thing foo = {Tree, {Acorn}};
    printf("foo.it = %d\n", foo.it);
    printf("foo.form.tree = %d\n", foo.form.tree);
    return 0;
}
```
- ���Թ������£�
```bash
$ gdb test1/union 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/union...
(gdb) show print union
Printing of unions interior to structures is on.
(gdb) b union.cpp:48
Breakpoint 1 at 0x120d: file test1/union.cpp, line 48.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/union 
data.i = 10
data.f = 0.000000
data.str = 

foo.it = 0
foo.form.tree = 1

Breakpoint 1, main () at test1/union.cpp:48
48          return 0;
(gdb) p data
$1 = {i = 10, f = 1.40129846e-44, str = "\n\000\000\000\000\000\000\000\200PUUUU\000\000\360\334\377\377"}
(gdb) p foo  ## �ṹ������������屻��ϸչʾ����
$2 = {it = Tree, form = {tree = Acorn, bug = Cocoon}}
(gdb) set print union off  ## �ر�
(gdb) show print union  
Printing of unions interior to structures is off.
(gdb) p data  ## ����������չʾ
$3 = {i = 10, f = 1.40129846e-44, str = "\n\000\000\000\000\000\000\000\200PUUUU\000\000\360\334\377\377"}
(gdb) p foo
$4 = {it = Tree, form = {...}}  ## ����Ϊoff֮�󣬽ṹ������������岻����ϸչʾ
```

- `set print object <on/off>`C++���һ������ָ��ָ���������࣬�򿪴�ѡ�GDB���Զ������鷽�����õĹ�����ʾ���������رմ�ѡ�GDB�Ͳ����麯����Ĭ����off
- ���Դ��룺
```C++
// object.cpp
#include <iostream>

class Base
{
public:
    virtual void show()
    {
        std::cout << "Base::show()" << std::endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    void show() override
    {
        std::cout << "Derived::show()" << std::endl;
    }
};

int main()
{
    Base *b = new Derived();
    b->show();
    delete b;
    return 0;
}
```
- ���Թ������£�
```bash
$ gdb test1/object 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/object...
(gdb) b object.cpp:26
Breakpoint 1 at 0x1229: file test1/object.cpp, line 26.
(gdb) show print object
Printing of object's derived type based on vtable info is off.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/object 
Derived::show()

Breakpoint 1, main () at test1/object.cpp:26
26          delete b;
(gdb) p b
$1 = (Base *) 0x55555556aeb0
(gdb) p *b
$2 = {_vptr.Base = 0x555555557d18 <vtable for Derived+16>}
(gdb) set print object on
(gdb) show print object 
Printing of object's derived type based on vtable info is on.
(gdb) p b
$3 = (Derived *) 0x55555556aeb0
(gdb) p *b
$4 = (Derived) {<Base> = {_vptr.Base = 0x555555557d18 <vtable for Derived+16>}, <No data fields>}
```
- ���`(Derived) {<Base> = {_vptr.Base = 0x555555557d18 <vtable for Derived+16>}, <No data fields>}`�������£�
- (Derived)����ʾ��������ʵ�������� Derived �ࡣ
- `{<Base> = ...}`����ʾ����������һ�� Base ����Ӷ������� Derived �̳��� Base������������һ�� Base ���Ӷ���
- _vptr.Base������ Base ����麯����ָ�롣���ָ��ָ���麯����vtable���ĵ�ַ��
- 0x555555557d18�������麯����ĵ�ַ��
- <vtable for Derived+16>����ʾ����麯����ʵ������ Derived ����麯������ַƫ��Ϊ +16��

- `set print static-members <on/off>`����ʾһ��C++�����е�����ʱ���Ƿ���ʾ���еľ�̬���ݳ�Ա��Ĭ����on
- `show print static-members`�鿴��̬���ݳ�Ա��ѡ������
- `set print vtbl <on/off>`��ʱ��GDB���ñȽϹ����ĸ�ʽ����ʾ�麯����Ĭ��off
- `show print vtbl`�鿴�麯����ʾ��ʽ��ѡ��

## ��ʷ��¼

- ʹ��print�鿴��������ʱ��GDB�����������ݱ��Ϊ$1,$2������ͨ����ŷ�����ǰ������

## GDB��������

- `set $foo = *object_ptr`�����Ը��������������κ�����
- `show convenience`�鿴��ǰ�����õ����еĻ�������
```bash
(gdb) set $foo = *b  ## ���û�������
(gdb) show convenience  ## �鿴���л�������
$foo = {_vptr.Base = 0x555555557d18 <vtable for Derived+16>}
$bpnum = 1
$_gdb_minor = 2
$_gdb_major = 9
$_any_caller_matches = <internal function _any_caller_matches>
$_any_caller_is = <internal function _any_caller_is>
$_caller_matches = <internal function _caller_matches>
$_caller_is = <internal function _caller_is>
$_regex = <internal function _regex>
$_streq = <internal function _streq>
$_strlen = <internal function _strlen>
$_memeq = <internal function _memeq>
$_as_string = <internal function _as_string>
$_inferior = 1
$_gdb_maint_setting = <internal function _gdb_maint_setting>
$_gdb_maint_setting_str = <internal function _gdb_maint_setting_str>
$_gdb_setting = <internal function _gdb_setting>
$_gdb_setting_str = <internal function _gdb_setting_str>
$_cimag = <internal function _cimag>
$_creal = <internal function _creal>
$_isvoid = <internal function _isvoid>
$_sdata = void
$_gthread = 1
$_thread = 1
$_probe_arg11 = <error: No probe at PC 0x0000555555555229>
$_probe_arg10 = <error: No probe at PC 0x0000555555555229>
$_probe_arg9 = <error: No probe at PC 0x0000555555555229>
$_probe_arg8 = <error: No probe at PC 0x0000555555555229>
$_probe_arg7 = <error: No probe at PC 0x0000555555555229>
$_probe_arg6 = <error: No probe at PC 0x0000555555555229>
$_probe_arg5 = <error: No probe at PC 0x0000555555555229>
$_probe_arg4 = <error: No probe at PC 0x0000555555555229>
$_probe_arg3 = <error: No probe at PC 0x0000555555555229>
$_probe_arg2 = <error: No probe at PC 0x0000555555555229>
```
- ʹ��ʾ����Ҫѭ�����һ������ʱ���������û�������$i��Ȼ��ѭ�����`set $i = 0`,`print bar[$i++]`��ѭ��ִ�к�������Ϳ���˳��������


## �鿴�Ĵ���

- `info registers`�鿴�Ĵ����������������Ĵ�����
- `info all-registers`�鿴���мĴ���
- `info registers <regname...>`�鿴ָ���ļĴ������
- ʹ��ʾ��
```bash
(gdb) info registers
rax            0x555555558040      93824992247872
rbx            0x55555556aeb0      93824992325296
rcx            0x7ffff7ce2297      140737350869655
rdx            0x0                 0
rsi            0x0                 0
rdi            0x7ffff7dc27e0      140737351788512
rbp            0x7fffffffdc00      0x7fffffffdc00
rsp            0x7fffffffdbe0      0x7fffffffdbe0
r8             0x0                 0
r9             0x0                 0
r10            0xfffffffffffff04a  -4022
r11            0x7ffff7c56340      140737350296384
r12            0x555555555100      93824992235776
r13            0x7fffffffdcf0      140737488346352
r14            0x0                 0
r15            0x0                 0
rip            0x555555555229      0x555555555229 <main()+64>
eflags         0x213               [ CF AF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
k0             0x0                 0
k1             0x0                 0
k2             0x0                 0
k3             0x0                 0
k4             0x0                 0
k5             0x0                 0
k6             0x0                 0
k7             0x0                 0
(gdb) info all-registers
rax            0x555555558040      93824992247872
rbx            0x55555556aeb0      93824992325296
rcx            0x7ffff7ce2297      140737350869655
rdx            0x0                 0
rsi            0x0                 0
rdi            0x7ffff7dc27e0      140737351788512
rbp            0x7fffffffdc00      0x7fffffffdc00
rsp            0x7fffffffdbe0      0x7fffffffdbe0
r8             0x0                 0
r9             0x0                 0
r10            0xfffffffffffff04a  -4022
r11            0x7ffff7c56340      140737350296384
r12            0x555555555100      93824992235776
r13            0x7fffffffdcf0      140737488346352
r14            0x0                 0
r15            0x0                 0
rip            0x555555555229      0x555555555229 <main()+64>
eflags         0x213               [ CF AF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
st0            0                   (raw 0x00000000000000000000)
st1            0                   (raw 0x00000000000000000000)
st2            0                   (raw 0x00000000000000000000)
st3            0                   (raw 0x00000000000000000000)
st4            0                   (raw 0x00000000000000000000)
st5            0                   (raw 0x00000000000000000000)
st6            0                   (raw 0x00000000000000000000)
st7            0                   (raw 0x00000000000000000000)
fctrl          0x37f               895
fstat          0x0                 0
--Type <RET> for more, q to quit, c to continue without paging--
ftag           0xffff              65535
fiseg          0x0                 0
fioff          0x0                 0
foseg          0x0                 0
fooff          0x0                 0
fop            0x0                 0
mxcsr          0x1f80              [ IM DM ZM OM UM PM ]
bndcfgu        {raw = 0x0, config = {base = 0x0, reserved = 0x0, preserved = 0x0, enabled = 0x0}} {raw = 0x0, config = {base = 0, reserved = 0, preserved = 0, enabled = 0}}
bndstatus      {raw = 0x0, status = {bde = 0x0, error = 0x0}} {raw = 0x0, status = {bde = 0, error = 0}}
k0             0x0                 0
k1             0x0                 0
k2             0x0                 0
k3             0x0                 0
k4             0x0                 0
k5             0x0                 0
k6             0x0                 0
k7             0x0                 0
pkru           0x55555554          1431655764
zmm0           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm1           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm2           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm3           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm4           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm5           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff,--Type <RET> for more, q to quit, c to continue without paging--
 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm6           {v16_float = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x7fffffffffffffff, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xff <repeats 16 times>, 0x0 <repeats 48 times>}, v32_int16 = {0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0 <repeats 24 times>}, v16_int32 = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x0 <repeats 12 times>}, v8_int64 = {0xffffffffffffffff, 0xffffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xffffffffffffffffffffffffffffffff, 0x0, 0x0, 0x0}}
zmm7           {v16_float = {0x0, 0x0, 0x0, 0xffffffff, 0x0 <repeats 12 times>}, v8_double = {0x8000000000000000, 0x7fffffffffffffff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, 0x0 <repeats 48 times>}, v32_int16 = {0xf1f0, 0xf3f2, 0xf5f4, 0xf7f6, 0xf9f8, 0xfbfa, 0xfdfc, 0xfffe, 0x0 <repeats 24 times>}, v16_int32 = {0xf3f2f1f0, 0xf7f6f5f4, 0xfbfaf9f8, 0xfffefdfc, 0x0 <repeats 12 times>}, v8_int64 = {0xf7f6f5f4f3f2f1f0, 0xfffefdfcfbfaf9f8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0xfffefdfcfbfaf9f8f7f6f5f4f3f2f1f0, 0x0, 0x0, 0x0}}
zmm8           {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm9           {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm10          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm11          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm12          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm13          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm14          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm15          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm16          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm17          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm18          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm19          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
zmm20          {v16_float = {0x0 <repeats 16 times>}, v8_double = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v64_int8 = {0x0 <repeats 64 times>}, v32_int16 = {0x0 <repeats 32 times>}, v16_int32 = {0x0 <repeats 16 times>}, v8_int64 = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, v4_int128 = {0x0, 0x0, 0x0, 0x0}}
--Type <RET> for more, q to quit, c to continue without paging--q
Quit
(gdb) info registers rax
rax            0x555555558040      93824992247872
(gdb) p $rax  ## ʹ��print �鿴�Ĵ���
$1 = 93824992247872
```

## �ı�����ִ��
- ʹ��GDB���Գ���ʱ�����Ը����Լ���˼·��̬���ĵ�ǰ���Գ����������·���߱�����ֵ

## �޸ı���ֵ
- `print x = 4`�޸�Ϊ4
- `set var var_name=xxx`���ñ���ֵ

## ��תִ��
- `jump <linespec>`ָ����һ���������е㣬`<linespec>`�������ļ����кţ�������`file:line`��ʽ��������`+num`����ƫ������ʽ
- `jump <address>`����ָ����ַ
- ע�⣬jump�����ı䵱ǰ����ջ�е����ݣ����ԣ���һ��������������һ������ʱ�����������귵��ʱ���е�ջ������Ȼ�ᷢ������������û�����ͬһ�������н�����ת��jump��Ҫ�Ǹı���ָ��Ĵ����е�ֵ
- ���Գ���
```C++
//jump.cpp
#include <iostream>

int main()
{
    int x = 0;
    int y = 1;
    int z = 2;
    std::cout << "Before jump: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    z = x + y;
    std::cout << "After jump: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    return 0;
}
```
- ���Թ���
```bash
$ gdb test1/jump 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/jump...
(gdb) b main
Breakpoint 1 at 0x11c9: file test1/jump.cpp, line 4.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/jump 

Breakpoint 1, main () at test1/jump.cpp:4
4       {
(gdb) n
5           int x = 0;
(gdb) 
6           int y = 1;
(gdb) 
7           int z = 2;
(gdb) jump 10
Continuing at 0x55555555526b.
After jump: x = 0, y = 1, z = 0  ## z��ֵû�б��޸�
[Inferior 1 (process 132450) exited normally]
```

## �����ź���

- `signal <signal>`�����ź�
- �����źţ�SIGINT (2): ��ֹ���̣�ͨ���� Ctrl+C ��������SIGKILL (9): ǿ����ֹ���̡�SIGTERM (15): ������ֹ���̡�SIGSEGV (11): ��Ч�ڴ����á�SIGABRT (6): �쳣��ֹ����
- ʹ�ó���
```C++
// signal1.cpp
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal)
{
    printf("Received signal: %d\n", signal);
}

int main()
{
    signal(SIGINT, handle_signal);
    printf("waiting for signal...\n");
    while (1)
    {
        sleep(1);
    }
    return 0;
}
```
- ���Խ��
```bash
$ gdb test1/signal1 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/signal1...
(gdb) signal SIGINT
The program is not being run.
(gdb) b main
Breakpoint 1 at 0x11d1: file test1/signal1.cpp, line 11.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/signal1 

Breakpoint 1, main () at test1/signal1.cpp:11
11      {
(gdb) n
12          signal(SIGINT, handle_signal);
(gdb) n
13          printf("waiting for signal...\n");
(gdb) n
waiting for signal...
16              sleep(1);
(gdb) signal SIGINT
Continuing with signal SIGINT.
Received signal: 2
```

## ǿ�ƺ�������

- ����ڵ��Թ����У�ĳ��������û��ִ���꣬����ʹ��return����ǿ�ƺ������Ի�û��ִ�������䲢����
- `return <expression>`
- ʹ�ó���
```C++
// return.cpp
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 4);
    printf("Result: %d\n", result);
    return 0;
}
```
- ���Թ���
```bash
$ gdb test1/return 
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test1/return...
(gdb) b add
Breakpoint 1 at 0x1149: file test1/return.cpp, line 4.
(gdb) r
Starting program: /home/aaa/bbb/ccc/GDBDebug/test1/return 

Breakpoint 1, add (a=21845, b=1431654816) at test1/return.cpp:4
4       {
(gdb) n
5           return a + b;
(gdb) p a
$1 = 3
(gdb) p b
$2 = 4
(gdb) return 10
Make add(int, int) return now? (y or n) y
#0  0x000055555555517c in main () at test1/return.cpp:10
10          int result = add(3, 4);
(gdb) n
11          printf("Result: %d\n", result);
(gdb) n
Result: 10
12          return 0;
```

## ǿ�ƺ�������

- `call <expr>`����`print func(a, b)`
- ʹ������ĳ���
```bash
(gdb) call add(1, 2)
$1 = 3
(gdb) print add(5, 6)
$2 = 11
(gdb) 
```

- �鿴��ǰ���Ե����Ի���`show language`
- `info frame`�鿴��ǰջ��Ϣ
- `info source`�鿴��ǰ�ļ��ĳ�������
```bash
(gdb) info source
Current source file is test1/return.cpp
Compilation directory is /home/aaa/bbb/ccc/GDBDebug
Located in /home/aaa/bbb/ccc/GDBDebug/test1/return.cpp
Contains 13 lines.
Source language is c++.
Producer is GNU C++14 9.4.0 -mtune=generic -march=x86-64 -g -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection.
Compiled with DWARF 2 debugging format.
Does not include preprocessor macro info.
```

## GDB�����ķ�ʽ
- `gdb program`������ִ���ļ�
- `gdb program core`������ִ���ļ���core dump�ļ�
- `gdb pid` ������Է�����򣬿���ָ��pid��GDB���Զ�attach

## GDB����ʱ���ÿ���
- `-symbols [file](-s)` ��ȡ�ļ��еķ��ű�
- `-exec [file](-e)` ����һ����ִ���ļ�
- `-se [file]` �϶��ߵ���д
- `-core [file] (-c)` ����һ��core dump�ļ�
- `-pid number (-p)` ����attachģʽ
- `-directory [directory] (-d)`���Դ��ɨ��·��
- `-readnow (-r)`һ�ζ�ȡ�����еķ��ű�
- `-quite -silent -q`����ģʽ������GDB������ʾ��Ȩҳ
- `-windows -w` ����GUI
- `-nowindows -nw` ���GDB����GUI�Ļ������ѡ���ص���
- `-cd [directory]` �л�����Ŀ¼Ϊdirectory���������ڵ�Ŀ¼
- `-tty [device] (-t)` ָ��deviceΪ��׼���
- `--args` �������Ҫ������������һ�����������Ĳ��������ɵ��Գ������

