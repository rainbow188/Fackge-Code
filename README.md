# Fackge
## 什么是 Fackge?
这是一款基于C++开发的脚本语言,十分简单,没有语法树,没有栈,全靠if嵌套,是不是很牛.
## 怎么使用fackge?
下载我们的编译文件,双击运行.
### 对Windows用户
下载我们的exe可执行文件使用
### 对Linux用户
下载我们的源码进行编译
## Fackgec1.0 开发版
### Fakcge F-- 1.0
- [x] Fackge 1.0.2
- [x] Fackge 1.0.3
- [x] Fackge 1.0.4
- [x] Fackge 1.0.5
- [x] Fackge 1.0.6
- [x] Fackge 1.0.6.1 Fixs
- [x] Fackge 1.0.6.2
- [x] Fackge 1.0.6.3
- [x] Fackge 1.0.6.4 Fixs
- [x] Fackge 1.7.0.4.3
### Fackge F-- 1.0 Sum分支
- [x] Fackge 1.0.6.5已合并
### Fackge F-- 1.0 Print分支
- [x] Fackge 1.7.0.3已合并
### Fackge F-- 1.0 Publicver分支
- [x] Fackge 1.0.6.5.3
- [x] Fackge 1.7.0.4.1 已合并
### Fackge F-- 1.0 Array分支
- [x] Fackge 1.7.0.4.1 Array Create
- [x] Fackge 1.7.0.4.1.5 Fixs
- [x] Fackge 1.7.0.4.5 Array
- [x] Fackge 1.7.0.4.5 Fixs
## Fackge 2.0
### 什么是Fackge2.0?
在1.0的基础上,我们重写了框架,更加高效的运行,同时修复bug,支持加载脚本文件
### 开发版
- [x] Fackge 2.0
- [x] Fackge 2.0 Fixs
- [x] Fackge 2.0.1
- [x] Fackge 2.0.2
- [x] Fackge 2.0.2 Fixs
- [x] Fackge 2.0.3
- [x] Fackge 2.0.3.5
- [x] Fackge 2.0.4
- [x] Fackge 2.0.4.5
- [x] Fackge 2.0.4.6
- [x] Fackge 2.0.5.0
- [x] Fackge 2.0.5.5 Fixs
- [ ] Fackge 2.0.6
### 2.0支持什么?
- [x] 加载自定义名字的插件
- [x] 更高的运行效率
- [x] 多线程加载插件
- [x] 更完善的系统
- [x] 个性化配置文件
- [x] 开发者模式
- [x] 抛出脚本错误
## Fackge Plugin
在Fackge2.0中,使用命令fload +脚本名字即可运行你的fackge插件
下面将对语法进行详细介绍.
### 入口函数fload{}
在fackge中,你需要一个头函数来使fackge读取你的代码,例如:
```
fload{
语句
语句
}
```
在fackge中,缺少入口函数,少了{或}都会报错。
###  逻辑函数math
在fackge中,所有逻辑运行都需要math模块,在使用相关运算之前,你必须使用:
```
import math
```
否则相关代码就会报错
Math模块十分强大,它可以进行运算,赋值和定义,下面将详细介绍它的函数
1.Publicver 创建变量函数
Publicver 也就是创建一个公用变量
使用方法一般是:
publicver [数据类型] [名字] = [内容]
例如:
```
import math
publicver int a = 10
```
看到了吗?这就是定义一个共有变量a为10
2.Math 计算函数
math 也就是计算赋值的函数
使用方法一般是:
math [数据] [运算符] [数据]
当然也可以这样用:
math [变量名] [运算符] [变量名]
math [变量名] = [数据值]
例如:
```
import math
publicver int a = 10
math a + 5
math a = 20
printf a
```
这段代码肯定会输出的是:
```
>>15
>>30
```
如果你仔细体会也能明白
3.Printf 打印函数
printf 也就是输出数据的函数
使用方法一般是:
printf [数据]
printf [变量名}
例如:

```
import math
publicver int a = 10
printf 16
printf a
```
这段代码一定会输出:
```
>>16
>>10
```
### 线程操作函数 fthread
在fackge中,由于对于条件语句,循环语句都需要fackge的处理,所以需要调用模块: FThread
调用方法: import fthread

1.条件语句 if 函数
if 也就是条件判断,成立则执行
在fakcge中的语法要求十分严格
比如是:
```
if 条件式
{
语句
语句
}
```
不能缺少{和}
否则会出现未知错误,因为{}在fakcge中是决定一个集合函数的开始和结束
