#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include<cstdlib> //support for exit()
#include <cmath>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

//FAPIXEL Studio 2019-2020 Fackge 
/*

- help (String) 获取帮助  完成 
- stop 停止运行  完成 
- new (String) 新建文件   
   - txt (int) 建立txt文件
   - f (int) 建立f可执行文件
      - Name (String) 文件名字
- version 版本信息  完成 
- checkupdate 获取更新    
- language (String) 切换语言  完成 
- printf (String/int/char/double) 输出 [此函数在math模块]   
   - String/int/char/double 例如printf (你好)  完成 
   - PublicVer 输出共用变量,必须是一个申明的变量  完成 
   - Command 可执行语句 例如printf ( sum 1+6 )
- rd (int,int) 生成随机数  完成 
- judge (int,int) 判断语句 完成 
   - int,int 判断整数返回布尔值 如 jduge (2 , 3) = false
- whiletask (double,double) 循环语句 完成 
   - double,double 循环累加一个值
- import (String) 调用模块  完成 
   - math 数学计算模块,提供如printf输出,sum计算等函数,同时也是f--标准库
   - turtle 海龟画图模块,提供如turtle-oblong等画图函数
- publicver (String)(String)(Char)(int/String/char) 定义变量(此函数在math模块)  完成 
   - int 定一个整数变量 例: publicver int a = 10  完成 
   - double 定一个浮点数 例: publucver double a = 10  完成
   - rand 定一个随机数 例: publicver rand(int) a = new rand(30) 完成 
- sum (int,char,int) 计算函数 (此函数在math模块) 完成
   - int+int 计算俩个整数的和 例: sum 1+2   完成 
   - PublicVer(int)+PublicVer(int) 计算俩个变量与变量或变量和具体数的和 例: sum a+10  完成 
- abs (int) 绝对值函数 (此函数在math模块)  完成 
   - int 取一个整数的绝对值 例: abs (-3) = 3   完成 
   - double 取一个浮点数的绝对值 例: abs (-3.14) = 3.14   完成 
- turtle (int,int) 画图 (此函数在turtle模块里)  完成 
- array (Sting) (String) 数组 完成 
   - int 定一个整数型号的数组 完成 
     - (String)(Char)(String)(int)创建数组 例: array int a = new array(30) 30为数组大小  完成
   - String 给一个已经创建的数组赋值 完成 
     - (char)(int) 赋值一个整数 例: array a(10) = 2 完成 


*/ 



	//自定义数组
	string NewArrayCase1[1000];
	string NewArrayCase2[1000]; 

int GetLength(const int tmp)
{
int count=0;
while( tmp/10 )
count++;
return count;
}

//rand函数
void rd(int i,int j)
{
	for(i;i<=1;i++)
	{
	cout<<rand()%j<<endl;
	}
};

//if函数
void judge(double ifa,char ifc,double ifb)
{
	if (ifc == '>')
	{
		if (ifa > ifb)
		{
			cout<<"true"<<endl;
		}else
		{
			cout<<"false"<<endl;
		}
	}

	if (ifc == '<')
	{
		if (ifa < ifb)
		{
			cout<<"true"<<endl;
		}else
		{
			cout<<"false"<<endl;
		}
	}

	if (ifc == '=')
	{
		if (ifa == ifb)
		{
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}
	 }


 };

 void whiletask(double a,double c)
 {
 	double time = 0.00;
 	int i=0;



 	if (a < c)
 	{
 		while (a<c)
 		{
 			Sleep(100);
 			time = time+0.01;
 			a++;
 			i++;
 			cout<<a<<endl;
		 }
	 }
	 cout<<"操作记录:"<<endl<<"循环次数:"<<i<<endl<<"耗时:"<<time<<endl;
	i = 0;
	time = 0.00;

  } ;





int main()
{
	int loadTask = 1;
	int SleepTask = 50;
	string loadIDE = "[----------]";
	int maxhelp = 1;
	const double Version = 107043;
    cout << "[INFO]加载 F--中,一款智能化的编程语言\n";
    string language;
    string debugmode = "true";
    string command, type, inputcharacter;
    string mdtime = "false";
    string mdmath = "false";
    string mdturtle = "false";
    string mdname;
    string casetype;

	//数组
	string ArrayNameCase[1000];
	int ArraySizeCase[1000];
	int ArrayCase[1000]; 
	int ArrayNumber = 0;
	

    //变量储存
	string PublicVer1[1000];
	int PublicVer2[1000];
	int taskver = 0;

    //Math Module
    //TODO:
   	int PublicVerCase = 0;
   	int PublicVerCase2 = 0;
   	int PublicVerSum = 0;


    int casesum = 0;
    
    int ThreadNumber = 1;
    
    

    language = "English";
    cout<<"[INFO]加载资源中"<<endl;
    /*en_main*/
    en_main:
    cout<<"[INFO]读取到语言配置: English-US"<<endl;
    cout<<"[F--]>Welcome to use F-- v"<<Version<<endl;
    cout<<"[F--]You can use /help to find commands helper"<<endl;
main:
	system("COLOR 7a");
	SetConsoleTitle("Fackge - C-- 虚拟机 | 线程数: 2  |");
    cout << "[F--]>";

   cin>>command;

    if (command == "help") {
    	cout<<"F-- v"<<Version<<" Help-----Page(1/"<<maxhelp<<")"<<endl;
    	cout<<"help [Command]: Get help"<<endl;
    	cout<<"stop [String]: Stop F--"<<endl;
    	cout<<"new [File]: New File"<<endl;
    	cout<<"version [Version]: F-- Version"<<endl;
    	cout<<"cheakupdate [Cheak]: Cheak new version"<<endl;
		cout<<"language [Language]: Change the language"<<endl;
		cout<<"printf [String]: Cout Message"<<endl;
		cout<<"rd [int int]:rank a number in (min)Int1 and (max)Int2"<<endl;
		cout<<"judge [double char double]: if()else"<<endl;
		cout<<"whiletask [double,double]: double1=start,double2=end"<<endl;
		cout<<"import [String]:Import the module.Such as: time/thread/math...."<<endl;
		cout<<"publicver [Type][String][Int]: extend it by defining a variable name."<<endl;
		cout<<"sum [Int/String]: summation."<<endl;
		cout<<"abs [Int]: abs command"<<endl;
		cout<<"turtle-oblong [int] [int]:draw a ablong"<<endl;
		cout<<"array [type][name]: New Array"<<endl;
        goto main;
    }
    else if (command == "stop") {
        cout << "Do you want to stop F-- system?(y/n)";
        string L;
        cin >> L;
        if (L == "y") {
            return 0;
        }
        else {
            goto main;
        }
    }
    else if (command == "judge")
    {
    	double ia,ib;

    	char ic;



    	cin>>ia>>ic>>ib;


    	judge(ia,ic,ib);
    	goto main;
	}
	else if (command == "fackge")
	{

		goto main;
	 }
	 else if (command == "abs")
	 {
	 	if (mdmath == "true")
	 	{
	 		int a;
	 		char b,c;
	 		cin>>b>>a>>c;
	 		cout<<">>>"<<abs(a)<<endl;

		 }
		 else{
		 	cout<<"[INFO]Unknow command."<<endl;
		 }
		 goto main;
	 }
	else if (command == "publicver")
	{
		if (mdmath == "true")
		{
			int typedebug = 1;
			char equic;
			string name;
			string size;
			string max;//rand类型变量的最大数 
			string randcommand;//new

			cin>>casetype;
			if (casetype == "int(int)")
			{
				typedebug = 0;
			}

			if (casetype == "rand(int)")
			{
				typedebug = 3;
			}

			if (casetype == "long(int)")
			{
				typedebug = 0;
			}

			switch (typedebug)
			{
				case 1 :
					cout<<"[ERROR]Unknow type."<<endl;
					goto main;
					break;
				default:
				break;
			}
			
			//int类型的变量定义 
			//Example: publicver int(int) a = 10
			if(typedebug == 0)
			{
			cin>>PublicVer1[taskver];


			cin>>equic;
			if (equic != '=')
			{
				cout<<"Error>>Char error"<<endl;
				goto main;
			}
			cin>>PublicVer2[taskver];


			taskver++;
			goto main;
}			
			//rand类型的
			//Example: publicver rand(int) a = new rand(3)
			if (typedebug == 3)
			{
				cin>>PublicVer1[taskver];
				cin>>equic;
					if (equic != '=')
			{
				cout<<"Error>>Char error"<<endl;
				goto main;
			}
				cin>>randcommand;
				if (randcommand != "new")
				{
					cout<<"Error: publucver command 49"<<endl;
					goto main;
				}
				cin>>max;
				string max1 = max.substr(5,max.length()-1);
				int max2=atoi(max1.c_str());
				PublicVer2[taskver] = rand()%max2;
				taskver++;
				goto main;
			}



		}else{
			goto main;
		}

		goto main;
	}
	else if (command == "import")
	{
		 cin>>mdname;
		 if (mdname == "time" && mdtime == "false")
		 {
		 	mdtime = "true";
		 }else if (mdname == "math" && mdmath == "false")
		 {
		 	mdmath = "true";
		 }else if(mdname == "turtle" && mdturtle == "false")
		 {
		 	mdturtle = "true";
		 }else
		 {
		 	cout<<">>>未知的模块或已被调用"<<endl;
		 }
		 goto main;
	}else if (command == "array")
	{
		//TODO : array
		//command: array (type) (name) = new array(size)
		//Example: array int a = new array(10)
		//注册: ArrayNameCase (string) 
		//注册: ArraySizeCase (int)
		//注册: ArrayCase (int) 
		//注册: ArrayNumber (int) 
		string ArrayCommand;//Array Command
		bool name = false;//Array Name Same 
		bool find = false;//Find the same Array Name
		char quic;// The '='
		int NewArrayID;//The Array ID
		string ArrayCase;
		int lengh5;
		string lengh4;
		int lengh1;//NewArrayName lengh
		//int lengh1 = GetLength(lengh);
				
		string namecase;//暂时储存 
		
		int number;
		
		int j = 1;
		
		
		cin>>ArrayCommand;
		if (ArrayCommand == "int" || ArrayCommand == "string")
		{
			cin>>ArrayNameCase[ArrayNumber];
			char add;
			cin>>add;
			if (add != '=')
			{
				cout<<"Error: Array must is a=b"<<endl;
				goto main;
			}
			string create;
			cin>>create;
			if (create != "new")
			{
				cout<<"Error: Create a array must use new"<<endl;
				goto main;
			}
			string NewArray;
			cin>>NewArray; 
			string a1 = NewArray.substr(6);
			//int last=strlen(a1); 编辑器错误
			int last = a1.length(); 
			string a2 = a1.substr(0,last-1);
			int size=atoi(a2.c_str());
			ArraySizeCase[ArrayNumber] = size;
			ArrayNumber++;
			//cout<<"大神你创建了一个类型为 int 名字为 "<<ArrayNameCase[ArrayNumber-1]<<" 大小为 "<<ArraySizeCase[ArrayNumber-1]<<" 的数组!"<<endl;
			goto main;
		}else {
			//判断数组是否存在 
			for (int i =0;i<=1000;i++)
			{
			
			
				
				//算法: while遍历字符串是否是name
				while (find != true)
				{
					
					if (ArrayCommand.substr(0,j) == ArrayNameCase[i])
					{
						namecase = ArrayCommand.substr(0,j);
						//cout<<"DEBUG>>找到了!名字为:"<<ArrayCommand.substr(0,j)<<"的数组是"<<ArrayNameCase[i]<<endl;
						lengh1 = namecase.length(); 
						lengh5 = lengh1;
						lengh4 = namecase;
						find = true;
						break;// D:
					}
					j++;
					//Sleep(100);
				 } 
				
				if (namecase == ArrayNameCase[i])
				{
					name = true;
					//cout<<"DEBUG>>检测到名字为"<<ArrayNameCase[i]<<"的数组,进入赋值模式"<<endl; 
					break;// D:
				}
			}
			if (name == true)
			{
				//TODO: 数组赋值 , 存储
				//Example: array a[0] = 1;
				//注册: NewArrayCase (string) 二位数组 储存
				//注册: NewArrayID (int) ID 
				//算法:  二维数组 , 遍历名字，对应id，然后储存 
				cin>>quic;
				if (quic != '=')
				{
					cout<<"Error: Array char error!"<<endl;
					goto main;
				 } 
				 cin>>number;
				 string stra=to_string(number);
				 ArrayCase = ArrayCommand.substr(lengh5+1,ArrayCommand.length()-1);
				 int ArrayCase1 = atoi(ArrayCase.c_str());//所储存的位置 
				 //开始储存
				for (int i = 0;i<=1000;i++)
				{
					if (ArrayNameCase[i] == lengh4)
					{
						//NewArrayCase[NewArrayID][ArrayCase1] = number;
						NewArrayCase1[NewArrayID] = NewArrayID;
					
						NewArrayCase2[ArrayCase1] = number;
						//cout<<"DEBUG>>成功将 "<<number<<" 储存到数组 "<<lengh4<<"["<<ArrayCase1<<"]中"<<endl;
						break;
					}
					
				 } 
				
				
			}
			
			goto main;
		}
		
		cout<<"Error: 107 Error:45 F--"<<endl;
		goto main;
	}
	else if (command == "turtle-oblong")
	{
		int i,j,max1,max2;
		string picture;

		cin>>max1>>max2>>picture;

		if (mdturtle == "true")
		{

			for (i=1;i<=max1;i++)
	{
		for (j=1;j<=max2;j++)
		cout<<picture;

		cout<<endl;

	}


		 } else {
		 	cout<<"[INFO]Unknow command"<<endl;
		 }
		goto main;

	}
	else if (command == "whiletask")
	{
		double whilea,whileb;
		char a,b,c;
		cin>>a>>whilea>>b>>whileb>>c;
		whiletask(whilea,whileb);
		goto main;
	}
	else if (command == "sum")
	{
		string sum1,sum2;
		char sumchar;
		bool ver;
		
		int sumcase1 = 0;
		int sumcase2 = 0;
		
		cin>>sum1>>sumchar>>sum2;
		
		
		int int1=atoi(sum1.c_str());
		int int2=atoi(sum2.c_str());
		
		if (sumchar=='+')
		{
			for (int i=0;i<=100;i++)
			{
				if (PublicVer1[i] == sum1)
				{
					//cout<<"遍历替换:"<<Publicver[i]<<endl;
					if(sumcase1 == 0)
					{
						sumcase1  = PublicVer2[i];
						//cout<<"遍历替换:"<<PublicVer1[i]<<" 到 sumcase1 值为"<<PublicVer2[i]<<endl;
					 }else
					 {
					 	sumcase2 = PublicVer2[i];
					 	//cout<<"遍历替换:"<<PublicVer1[i]<<" 到 sumcase2 值为"<<PublicVer2[i]<<endl;
					  } 
					  
					  ver = true;
				}
				
				if (PublicVer1[i] == sum2)
				{
					if(sumcase1 == 0)
					{
						sumcase1  = PublicVer2[i];
						//cout<<"遍历替换:"<<PublicVer1[i]<<" 到 sumcase1 值为"<<PublicVer2[i]<<endl;
					 }else
					 {
					 	sumcase2 = PublicVer2[i];
					 	//cout<<"遍历替换:"<<PublicVer1[i]<<" 到 sumcase2 值为"<<PublicVer2[i]<<endl;
					  } 
					  
					  ver = true;
				}
			}
			
			if (ver == true)
			{
				if (sumcase1!=0&&sumcase2!=0)
				{
					cout<<">>"<<sumcase1+sumcase2<<endl;
				}
				if (sumcase1!=0&&sumcase2==0)
				{
					cout<<">>"<<sumcase1+int2<<endl; 
				}
				if (sumcase1==0&&sumcase2!=0)
				{
					cout<<">>"<<int1+sumcase2<<endl;
				}
				//TODO: 避免神必错误 
				if (sumcase1==0&&sumcase2==0)
				{
					cout<<">>"<<int1+int2<<endl;
					ver = false; 
				}
			}else
			{
				cout<<">>"<<int1+int2<<endl;
			}
			
			}	
		
		

		goto main;
	}
    else if (command == "rd")
    {
    	string a,b;
    	int debugsize;
    	int min,max;
    	string fg;
    	cin>>a>>min>>fg>>max>>b;
    	if (a != "(")
    	debugsize = 1;
    	if (fg != ",")
    	debugsize = 1;
    	if (b != ")")
    	debugsize = 1;

    	switch (debugsize)
    	{
    		case 1:
    			cout<<"[ERROR] cd(int,int)"<<endl;

    			break;
    		default:
			break;
		}

		rd(min,max);
		goto main;

	}
    else if (command == "new") {
        cout << "[F--]>File>";
        cout<<"[INFO] use (.)txt/(.)f to create new file"<<endl;
        string edit;
		string ss;
		string filename;
		int typeID;
        cin >> type;
        if (type == "txt")
        {
        	typeID = 1;
		}
        switch (typeID)
        {
        	case 1:

			cout<<"[INFO] You create a txt file"<<endl;
			cout<<"[INFO] Input its name?"<<endl;

			cin >> filename;
			cout<<"[INFO] You create a File "<<filename<<".txt"<<endl;
			cout<<"[INFO]Do you want to edit this file?(y/n)"<<endl;
        	cin >> edit;
        	if (edit == "y")
        	{

        		cout<<"[INFO]Open the "<<filename<<".txt now!"<<endl;
        		Sleep(2000);
        		cout<<"\n\n\n\n\n\n\n\n\n\nFILE: "<<filename<<".txt"<<endl;
        		cout<<"You can edit now!"<<endl;
        		cin>> ss;
        		cout<<"[INFO]Save now."<<endl;
			}
			else
			{
				goto main;
			}
			break;

			default:
				cout<<"[INFO] Unknow file"<<endl;

        	break;

		}
        goto main;
    }
    else if (command == "version") {
		cout<<"[VERSION] F-- v"<<Version<<endl<<"Made by FAPixel Team"<<endl<<"Version: 202020"<<endl;
	    goto main;
    }
    else if (command == "cheakupdate") {
        cout << "[INFO] Cheaking the new Version now......";
        Sleep(5000);
        cout<<"[SERVER] No new version"<<endl;
        goto main;
    }
    else if (command == "printf"){
    	string printf;
    	cin>>printf;
    	int SizeCase=printf.length();//截取长度 
    	string printcheak = printf.substr(1,SizeCase-2);
    	int debug = 0;
 
//    	if (printf.substr(0,1) != "(")
// 	  	{
//    		cout<<"[ERROR]substr0被我获取到为 "<<printf.substr(0)<<endl;
//    		cout<<"ERROR: CharError"<<endl;
//    		goto main;
//		}else if (printf.substr(0,SizeCase-1) != ")")
//		{
//			cout<<"[DEBUG]SizeCase-1 被我获取到为 "<<printf.substr(SizeCase-1)<<endl;
//			cout<<"ERROR: CharError"<<endl;
//			goto main;
//		}
//算法不行,第二种算法

		if (printf.substr(0,1) == "(" && printf.substr(SizeCase-1,1) == ")")
		{
			
		  } else
		  {
		  	cout<<"ERROR: CharError"<<endl;
			//cout<<"[DEBUG] 我他妈又来黑魔法草,收集: "<<endl<<"第一个检查点: "<<printf.substr(0,1)<<endl<<"第二个检查点: "<<printf.substr(SizeCase-1,1)<<endl;
		  	goto main;
		   } 

    	for (int i = 0;i <= 100;i++)//遍历PublicVer 
    	{


    		if (PublicVer1[i] == printcheak)
    		{

    			cout<<">>>"<<PublicVer2[i]<<endl;
    			goto main;
			}

			debug = 1;
		}

		if (debug == 1)
		{
			cout<< ">>>" << printf.substr(1,SizeCase-2) <<endl ; 
		}




		goto main;
	}
	else if (command == " ")
	{
		cout<<"[INFO] Unknow command!"<<endl;
		goto main;
	}
    else if (command == "language") {
        cout << "Please enter the setting language(English/中文):"<<endl;
        string language;
        cin >> language;
        if (language == "English") {
            goto main;
        }
        else if (language == "中文") {
            goto ch;
        }
        else {
            cout << "[INFO]Unknown language.\n";
            goto main;
        }
    }
    else {
        cout << "[INFO]Unknown command\n";
        system("cls");
        goto main;
    }

    /*cn_main*/
ch:
    language = "中文";
    cout<<"[DEBUG]中文部分暂未开发"<<endl;
cn_main:
    cout << "[F--]>";
    cin >> command;
    if (command == "帮助") {
        cout<<"暂未开发"<<endl;
        cout<<"请输入back"<<endl;
        goto cn_main;
    }
    else if (command == "back") {
        cout << "你确定要返回吗(是/否)";
        string retuen1;
        cin >> retuen1;
        if (retuen1 == "是") {
            goto main;
        }
        else {
            goto cn_main;
        }
    }







}
