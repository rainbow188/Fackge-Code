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

- help (String) ��ȡ����  ��� 
- stop ֹͣ����  ��� 
- new (String) �½��ļ�   
   - txt (int) ����txt�ļ�
   - f (int) ����f��ִ���ļ�
      - Name (String) �ļ�����
- version �汾��Ϣ  ��� 
- checkupdate ��ȡ����    
- language (String) �л�����  ��� 
- printf (String/int/char/double) ��� [�˺�����mathģ��]   
   - String/int/char/double ����printf (���)  ��� 
   - PublicVer ������ñ���,������һ�������ı���  ��� 
   - Command ��ִ����� ����printf ( sum 1+6 )
- rd (int,int) ���������  ��� 
- judge (int,int) �ж���� ��� 
   - int,int �ж��������ز���ֵ �� jduge (2 , 3) = false
- whiletask (double,double) ѭ����� ��� 
   - double,double ѭ���ۼ�һ��ֵ
- import (String) ����ģ��  ��� 
   - math ��ѧ����ģ��,�ṩ��printf���,sum����Ⱥ���,ͬʱҲ��f--��׼��
   - turtle ���껭ͼģ��,�ṩ��turtle-oblong�Ȼ�ͼ����
- publicver (String)(String)(Char)(int/String/char) �������(�˺�����mathģ��)  ��� 
   - int ��һ���������� ��: publicver int a = 10  ��� 
   - double ��һ�������� ��: publucver double a = 10  ���
   - rand ��һ������� ��: publicver rand(int) a = new rand(30) ��� 
- sum (int,char,int) ���㺯�� (�˺�����mathģ��) ���
   - int+int �������������ĺ� ��: sum 1+2   ��� 
   - PublicVer(int)+PublicVer(int) �����������������������;������ĺ� ��: sum a+10  ��� 
- abs (int) ����ֵ���� (�˺�����mathģ��)  ��� 
   - int ȡһ�������ľ���ֵ ��: abs (-3) = 3   ��� 
   - double ȡһ���������ľ���ֵ ��: abs (-3.14) = 3.14   ��� 
- turtle (int,int) ��ͼ (�˺�����turtleģ����)  ��� 
- array (Sting) (String) ���� ��� 
   - int ��һ�������ͺŵ����� ��� 
     - (String)(Char)(String)(int)�������� ��: array int a = new array(30) 30Ϊ�����С  ���
   - String ��һ���Ѿ����������鸳ֵ ��� 
     - (char)(int) ��ֵһ������ ��: array a(10) = 2 ��� 


*/ 



	//�Զ�������
	string NewArrayCase1[1000];
	string NewArrayCase2[1000]; 

int GetLength(const int tmp)
{
int count=0;
while( tmp/10 )
count++;
return count;
}

//rand����
void rd(int i,int j)
{
	for(i;i<=1;i++)
	{
	cout<<rand()%j<<endl;
	}
};

//if����
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
	 cout<<"������¼:"<<endl<<"ѭ������:"<<i<<endl<<"��ʱ:"<<time<<endl;
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
    cout << "[INFO]���� F--��,һ�����ܻ��ı������\n";
    string language;
    string debugmode = "true";
    string command, type, inputcharacter;
    string mdtime = "false";
    string mdmath = "false";
    string mdturtle = "false";
    string mdname;
    string casetype;

	//����
	string ArrayNameCase[1000];
	int ArraySizeCase[1000];
	int ArrayCase[1000]; 
	int ArrayNumber = 0;
	

    //��������
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
    cout<<"[INFO]������Դ��"<<endl;
    /*en_main*/
    en_main:
    cout<<"[INFO]��ȡ����������: English-US"<<endl;
    cout<<"[F--]>Welcome to use F-- v"<<Version<<endl;
    cout<<"[F--]You can use /help to find commands helper"<<endl;
main:
	system("COLOR 7a");
	SetConsoleTitle("Fackge - C-- ����� | �߳���: 2  |");
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
			string max;//rand���ͱ���������� 
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
			
			//int���͵ı������� 
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
			//rand���͵�
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
		 	cout<<">>>δ֪��ģ����ѱ�����"<<endl;
		 }
		 goto main;
	}else if (command == "array")
	{
		//TODO : array
		//command: array (type) (name) = new array(size)
		//Example: array int a = new array(10)
		//ע��: ArrayNameCase (string) 
		//ע��: ArraySizeCase (int)
		//ע��: ArrayCase (int) 
		//ע��: ArrayNumber (int) 
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
				
		string namecase;//��ʱ���� 
		
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
			//int last=strlen(a1); �༭������
			int last = a1.length(); 
			string a2 = a1.substr(0,last-1);
			int size=atoi(a2.c_str());
			ArraySizeCase[ArrayNumber] = size;
			ArrayNumber++;
			//cout<<"�����㴴����һ������Ϊ int ����Ϊ "<<ArrayNameCase[ArrayNumber-1]<<" ��СΪ "<<ArraySizeCase[ArrayNumber-1]<<" ������!"<<endl;
			goto main;
		}else {
			//�ж������Ƿ���� 
			for (int i =0;i<=1000;i++)
			{
			
			
				
				//�㷨: while�����ַ����Ƿ���name
				while (find != true)
				{
					
					if (ArrayCommand.substr(0,j) == ArrayNameCase[i])
					{
						namecase = ArrayCommand.substr(0,j);
						//cout<<"DEBUG>>�ҵ���!����Ϊ:"<<ArrayCommand.substr(0,j)<<"��������"<<ArrayNameCase[i]<<endl;
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
					//cout<<"DEBUG>>��⵽����Ϊ"<<ArrayNameCase[i]<<"������,���븳ֵģʽ"<<endl; 
					break;// D:
				}
			}
			if (name == true)
			{
				//TODO: ���鸳ֵ , �洢
				//Example: array a[0] = 1;
				//ע��: NewArrayCase (string) ��λ���� ����
				//ע��: NewArrayID (int) ID 
				//�㷨:  ��ά���� , �������֣���Ӧid��Ȼ�󴢴� 
				cin>>quic;
				if (quic != '=')
				{
					cout<<"Error: Array char error!"<<endl;
					goto main;
				 } 
				 cin>>number;
				 string stra=to_string(number);
				 ArrayCase = ArrayCommand.substr(lengh5+1,ArrayCommand.length()-1);
				 int ArrayCase1 = atoi(ArrayCase.c_str());//�������λ�� 
				 //��ʼ����
				for (int i = 0;i<=1000;i++)
				{
					if (ArrayNameCase[i] == lengh4)
					{
						//NewArrayCase[NewArrayID][ArrayCase1] = number;
						NewArrayCase1[NewArrayID] = NewArrayID;
					
						NewArrayCase2[ArrayCase1] = number;
						//cout<<"DEBUG>>�ɹ��� "<<number<<" ���浽���� "<<lengh4<<"["<<ArrayCase1<<"]��"<<endl;
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
					//cout<<"�����滻:"<<Publicver[i]<<endl;
					if(sumcase1 == 0)
					{
						sumcase1  = PublicVer2[i];
						//cout<<"�����滻:"<<PublicVer1[i]<<" �� sumcase1 ֵΪ"<<PublicVer2[i]<<endl;
					 }else
					 {
					 	sumcase2 = PublicVer2[i];
					 	//cout<<"�����滻:"<<PublicVer1[i]<<" �� sumcase2 ֵΪ"<<PublicVer2[i]<<endl;
					  } 
					  
					  ver = true;
				}
				
				if (PublicVer1[i] == sum2)
				{
					if(sumcase1 == 0)
					{
						sumcase1  = PublicVer2[i];
						//cout<<"�����滻:"<<PublicVer1[i]<<" �� sumcase1 ֵΪ"<<PublicVer2[i]<<endl;
					 }else
					 {
					 	sumcase2 = PublicVer2[i];
					 	//cout<<"�����滻:"<<PublicVer1[i]<<" �� sumcase2 ֵΪ"<<PublicVer2[i]<<endl;
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
				//TODO: ������ش��� 
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
    	int SizeCase=printf.length();//��ȡ���� 
    	string printcheak = printf.substr(1,SizeCase-2);
    	int debug = 0;
 
//    	if (printf.substr(0,1) != "(")
// 	  	{
//    		cout<<"[ERROR]substr0���һ�ȡ��Ϊ "<<printf.substr(0)<<endl;
//    		cout<<"ERROR: CharError"<<endl;
//    		goto main;
//		}else if (printf.substr(0,SizeCase-1) != ")")
//		{
//			cout<<"[DEBUG]SizeCase-1 ���һ�ȡ��Ϊ "<<printf.substr(SizeCase-1)<<endl;
//			cout<<"ERROR: CharError"<<endl;
//			goto main;
//		}
//�㷨����,�ڶ����㷨

		if (printf.substr(0,1) == "(" && printf.substr(SizeCase-1,1) == ")")
		{
			
		  } else
		  {
		  	cout<<"ERROR: CharError"<<endl;
			//cout<<"[DEBUG] ������������ħ����,�ռ�: "<<endl<<"��һ������: "<<printf.substr(0,1)<<endl<<"�ڶ�������: "<<printf.substr(SizeCase-1,1)<<endl;
		  	goto main;
		   } 

    	for (int i = 0;i <= 100;i++)//����PublicVer 
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
        cout << "Please enter the setting language(English/����):"<<endl;
        string language;
        cin >> language;
        if (language == "English") {
            goto main;
        }
        else if (language == "����") {
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
    language = "����";
    cout<<"[DEBUG]���Ĳ�����δ����"<<endl;
cn_main:
    cout << "[F--]>";
    cin >> command;
    if (command == "����") {
        cout<<"��δ����"<<endl;
        cout<<"������back"<<endl;
        goto cn_main;
    }
    else if (command == "back") {
        cout << "��ȷ��Ҫ������(��/��)";
        string retuen1;
        cin >> retuen1;
        if (retuen1 == "��") {
            goto main;
        }
        else {
            goto cn_main;
        }
    }







}
