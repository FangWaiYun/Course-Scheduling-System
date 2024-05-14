EasyX for MinGW
https://go.easyx.cn/easyx-for-mingw
------------------------------------

[支持 MinGW 的版本]
TDM-GCC 4.8.1 及以上版本，支持 32 位和 64 位。
MinGW-w64 的支持有限，支持 x86_64-posix-seh、x86_64-win32-seh、i686-posix-sjlj、i686-win32-sjlj，但不支持 x86_64-posix-sjlj、x86_64-win32-sjlj、i686-posix-dwarf、i686-win32-dwarf。

[支持编译器的版本]
使用 TDM-GCC 4.8.1 及以上版本的集成开发环境都可以支持。例如：
● Code::Blocks 13.12 及以上版本
● DevCpp 5.8.0 及以上版本
同时额外支持：
● DevCpp 5.4.0 GCC MinGW 4.7.2
● C-Free 5.0（内置 GCC MinGW 3.4.5）

[文件列表]
include			头文件
lib32			32 位库文件
lib64			64 位库文件
lib-for-devcpp_5.4.0	仅适用于 DevCpp 5.4.0 MinGW 4.7.2 和 C-Free 5.0

[安装方法]
将 include 文件夹下的头文件和 lib32/lib64 文件夹下的库文件，分别拷贝到 MinGW 的头文件和库文件文件夹中，链接选项增加：-leasyx，然后编译即可。