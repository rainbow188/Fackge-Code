#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool debug = false;
string version = "2.0.5.6";

mutex mtx;//�����߳� 

string CommandManager[10000];//�������� 
string CommandDPT[10000];//����������� 
int CommandNumber = 0;//ע�������� 

string PVNameCase[10000];//����������� 
int PVCase[10000];//����������� 
int PVNumber = 0;//ע��������� 
string str[3];//����Mod��������Ĺ�ϵ 

bool math = false;//mathģ���Ƿ��� 
int Math1;//�������� 
int Math2;//�������� 

bool FThread = false; //threadģ���Ƿ��� 

bool Ifoff=true;//��ȡ�Ƿ���if������� 
int IfLine=-10;//����if��俪ʼ���� 
int IfA;//���� 
int IfB;//���� 
bool IfLoad=false;//�Ƿ�����if 
bool CanLoad=false;//�Ƿ���� 

float PluginLoadTime = 0;//�������ʱ�� 
string ThreadTask = "start";

const char*LONLAT;

void loadfile();
void CommandPrintf(int mode,string filenumber);
void getLogger(string info,int type); 
void ImportF(int mode);
void PublicVer(int mode,string str1,int str2);
void Math(int mode,char ch,int number1,int number2,int line,string ch2);
void IsPublicVer(string number1,string number2);
void PluginLoadBefore();

//ע������
void RigCommand(string command,string depcommand){
	CommandManager[CommandNumber] = command;
	CommandDPT[CommandNumber] = depcommand;
	CommandNumber++;
	cout<<"[INFO]����"<<command<<"ע��ɹ�!"<<endl; 
} 


//�����������ı���
void PluginLoadBefore()
{
	while(true)
	{
	if (ThreadTask!="stop"){
	PluginLoadTime = PluginLoadTime+0.001;
	sleep(10);
}else{
	cout<<"����ʱ��:"<<PluginLoadTime<<endl;
	break;
}
	}
	
}

//��ȡ��������� 
int GetTxtLine(const char *filename)
{
    FILE *fd;
    int count = 0;
    if (fd = fopen(filename,"r"))
    {
        while (!feof(fd))
        {
            if ('\n' == fgetc(fd))
            {
                count ++;
            }
        }
    }
    if (fd)
    {
        fclose(fd);
    }
    return count;
}

//��ʾ����:
void error(string type,string why,int line)
{
	cout<<"ERROR: "<<type<<endl;
	cout<<why<<" ������:"<<line<<endl;
 } 

//������ִ�����
void CleanPluginCase()
{
	math = false;//��ԭ����
	for (int i = 0;i<=PVNumber;i++)
	{
		PVNameCase[i]="";
		PVCase[i] = 0;
	 } 
	PVNumber=0; 
	IfLine=-10;
	Ifoff=true;
	IfA=rand()%9999;
	IfB=rand()%9999;
	IfLoad=false;
	CanLoad=false;
	PluginLoadTime = 0;
	ThreadTask = "start";

	
	getLogger("���plugin.f�������",1);
 } 


//������Ϣ 
void getLogger(string info,int type){

	switch(type)
	{
		case 1:
			cout<<"[INFO]"<<info<<endl;
			break;
		case 2:
			cout<<"[WARING]"<<info<<endl;
			break;
		case 3:
			if (debug==true)
			cout<<"[DEBUG]"<<info<<endl;
			break;
		default:
			cout<<">>"<<info<<endl;
			break;			
	}
	
}

//ִ�б���command
void SendCommand(string command,int mode,int line,int end){
	if (command=="help"){
			cout<<"Fackge "<<version<<" Command List ["<<CommandNumber<<"]"<<endl;
			for (int i=0;i<CommandNumber;i++)
			{
				cout<<CommandManager[i]<<"===�÷�:"<<CommandDPT[i]<<endl;
			}
			return;
		}else if(command=="fload"){
			thread thrd_1(loadfile);//���ز���ƽ����߳� 
			thread thrd_2(PluginLoadBefore);
			thrd_1.join(); 
			thrd_2.join();
		}else if (command=="printf"){ 
			CommandPrintf(1,"666");
			return;
		}else if (command=="import"){
		ImportF(1);
		}else if (command=="publicver"&&math==true){
		PublicVer(1,"",1);
		}else if (command=="math"&&math==true)
		{
		Math(1,'+',0,0,0,"");
		}else if (mode==2&&line!=1&&line!=end)
		{
			if(command.substr(0,2)!="//")
			{ 
			if (Ifoff==true)
			{ 
			//cout<<"��ʱifoffΪ"<<Ifoff<<endl; 
			error("Fackge ThreadTask error","This is a void function",line);
			return;
			} 
			} 
		 }
} 

//ִ�� 
void fileprint(string command,int line){
	

	
	if (line==1)
	getLogger("���ز�� plugin.f ��....",1);
	
	
	//cout<<"[DEBUG] IFLoad:"<<IfLoad<<endl<<"CanLoad:"<<CanLoad<<endl<<"Ifoff:"<<Ifoff<<endl; 
	
	//�������if��� 
	if (line==IfLine+1)
	{
	//	 cout<<"������,��ִ������"<<endl;
		if (command!="{")
		{
			error("Fackge CommandManager error","NULL in function thread",line);
			Ifoff=true;
			return;
		}else{
			Ifoff=false;
			return;
		} 
	}
	
	//�������if���
		if (command=="}")
			if(line!=GetTxtLine(LONLAT))
				if(Ifoff==true)
				{
					error("Fackge ThreadTask error","The } is more there.",line);
					return;
				}else{
					Ifoff=true;
					IfLoad=false;
					CanLoad=true;
					IfLine=-10;
	//				cout<<"�ɹ�����if"<<endl; 
					return;
				}
	//�����쳣��if���
		if (command=="}"&&line==GetTxtLine(LONLAT)&&Ifoff==false)
		{
			error("Fackge ThreadTask error","too few arguments to function Thread",line);
			return;
					}			
				
	//����If������ 
	
	if (Ifoff==false&&IfLoad==true)
	{
	//	cout<<"���ǳ���if"<<endl;
		CanLoad=true; 
	}else if(Ifoff==false&&IfLoad==false)
	{
	//	cout<<"������if ����:"<<line<<endl;
		CanLoad=false;
	 }else if(Ifoff==true&&IfLoad==false)
		{
	//		cout<<"��ͨ���"<<endl;
			CanLoad=true;
		}else{
			error("Fackge ThreadTask error","IFLoad Case error",line);
			return;
		}

	if(CanLoad==true)
	{
	
	if (line==1&&command!="fload{"){
		error("Fackge CommandManager error","No Main function in it",1);
		return;
	}else if (line==GetTxtLine(LONLAT)+1&&command!="}")
	{
		error("Fackge ThreadTask error","Plugin: expected } in the last",GetTxtLine(LONLAT)+1);
		return;
	}else if (command.substr(0,6)=="printf")
	{
		int end = command.length();
		string str1 = command.substr(8,end);
		CommandPrintf(2,str1);
	}else if (command.substr(0,6)=="import"){
		int end = command.length();
		string str1 = command.substr(7,end);
		//cout<<"��׽��"<<str1<<endl; 
		
		if(str1=="math")
		{
		ImportF(2);
		return;
	}else{
		error("Fackge CommandManager error","Unknow dlls for fackge",line);
		return;
	}
	}else if (command.substr(0,9)=="publicver"&&math==true){
		int end = command.length();
		string str1 = command.substr(14,end);//��һ��,ȥ��publucver
		string pv;
		istringstream is(str1);
		is>>str[0]>>str[1]>>str[2];
		int end2 = pv.length();
		pv = str[2].substr(0,end2-1);
		//cout<<endl<<str[0]<<endl<<str[1]<<endl<<str[2]<<endl;
		if (str[1]!="=")
		{
			error("Fackge PublicverTask error","char error",line);
			return;
				}
		
		int pvnb = atoi(pv.c_str());	
		
		PublicVer(2,str[0],pvnb);				
		return;
	}else if (command.substr(0,4)=="math"&&math==true){
		int end = command.length();
		int where;//��¼iֵ 
		string str1 = command.substr(5,end);
		string pv;
		istringstream is(str1);
		is>>str[0]>>str[1]>>str[2];
		pv=str[0];
			
		if (str[1]=="=")
		{
			bool pubcheck=false;
			for (int i = 0;i<=PVNumber;i++)
			{
				if (PVNameCase[i]==pv)
				{
					pubcheck=true;
					where = i;
					i=PVNumber;
				}
			}
				
				if (pubcheck==true)
				{
					PVCase[where]=stoi(str[2]);
					
				}else{
					error("Fackge PublicverCase error","This is a error publicver",line);
					return;
				}
				 
				}else {
				IsPublicVer(str[0],str[2]);
				
				Math(2,'+',Math1,Math2,line,str[1]);
			}
		
	}else if (command.substr(0,2)=="if"){
		//cout<<command.substr(0,2)<<endl;
		getLogger("����һ���������",3);
		int end = command.length();
		string str1 = command.substr(3,end);//�Ժ�Ҫע���������� 
		istringstream is(str1);
		is>>str[0]>>str[1]>>str[2];
		//cout<<"������:"<<endl<<str[0]<<endl<<str[1]<<endl<<str[2]<<endl<<endl;
		
		for (int i = 0;i<=PVNumber;i++)
		{
			bool check1=false;
			bool check2=false;
			
			if (check1==false)
			{
			if (str[0]==PVNameCase[i])
			{
				IfA=PVCase[i];
				check1=true;
			}
		}
		
			if (check2==false)
			{
			if (str[2]==PVNameCase[i])
			{
				IfB=PVCase[i];
				check2=true;
			}
		}
			
			if (i==PVNumber-1)
			{
				if (check1==false)
				IfA=stoi(str[0]);
				if (check2==false)
				IfB=stoi(str[2]);
			}
			
		 } 
		
		//cout<<endl<<endl<<IfA<<endl<<IfB<<endl<<endl;
		
		if(str[1]=="==")
		{
			IfLine = line;
	//		cout<<"��һ�ؼ��if�ǳɹ���� ��¼:"<<IfLine<<endl;
		
	//		cout<<"[DEBUG]������,IFAΪ"<<IfA<<" IFBΪ"<<IfB<<endl;
			if (IfA==IfB)
			{
	//			cout<<"IFA==IFB����!"<<endl;
				IfLoad=true;
	//			cout<<"IFLOAD==true"<<endl;
			}else
			{
				IfLoad=false;
			}
			return;
		}
		
		
				if(str[1]==">")
		{
			IfLine = line;
	//		cout<<"��һ�ؼ��if�ǳɹ���� ��¼:"<<IfLine<<endl;
			
	//		cout<<"[DEBUG]������,IFAΪ"<<IfA<<" IFBΪ"<<IfB<<endl;
			if (IfA>IfB)
			{
	//			cout<<"IFA==IFB����!"<<endl;
				IfLoad=true;
	//			cout<<"IFLOAD==true"<<endl;
			}else
			{
				IfLoad=false;
			}
			return;
		}
		
		
				if(str[1]=="<")
		{
			IfLine = line;
	//		cout<<"��һ�ؼ��if�ǳɹ���� ��¼:"<<IfLine<<endl;
		
	//		cout<<"[DEBUG]������,IFAΪ"<<IfA<<" IFBΪ"<<IfB<<endl;
			if (IfA<IfB)
			{
	//			cout<<"IFA==IFB����!"<<endl;
				IfLoad=true;
	//			cout<<"IFLOAD==true"<<endl;
			}else
			{
				IfLoad=false;
			}
			return;
		}
		
		return;
		
	}else{
	SendCommand(command,2,line,GetTxtLine(LONLAT));
}
}else{
	return;
}
}

//���� 
void loadfile(void){
	char c[20];
	bool Ifloadfile = true; 
	string filename;
	cin>>filename;
	int end = filename.length();
	if(filename.length()>=3)
	{
	if (filename.substr(end-2,end)!=".f")
	{
		error("Fakcge ThreadTask error","Only can run fackge plugin(.f) file",0);
		Ifloadfile = false;
	 } 
}else{
	error("Fackge ThreadTask error","Fackge plugin file name lengh must > 3",0);
	Ifloadfile = false;
}
  	strcpy(c,filename.c_str());
  
  LONLAT = c;
  const char *filePath = c;
  ifstream file;
  file.open(filePath,ios::in);
 
  if(!file.is_open()){
 		getLogger("�޷��ҵ� ����ļ� ���Լ���ʧ��",2);
        Ifloadfile = false;
    }
 
    if (Ifloadfile==true)
    {
       std::string strLine;
       int Line = 1;
       while(getline(file,strLine))
       {
 
            if(strLine.empty())
                continue;
 
            //cout<<strLine <<endl;    
			//if (debug==true)
			//cout<<strLine<<endl;
			
			
			fileprint(strLine,Line);
			Line++;
			
			str[0]="";
			str[1]="";
			str[2]="";
			
       } 
      ThreadTask = "stop";//������ʱ�� 
      sleep(100);
      CleanPluginCase();
}else{
	ThreadTask="stop";
	sleep(100);
}

}

//�����ļ�
void loadconfig(void){
	  const char *filePath = "fackge.setting";
  ifstream file;
  file.open(filePath,ios::in);
 
  if(!file.is_open()){
 		error("Fackge Enable loadconfig","����fackge.settingʱ����δ֪����",109);
        return; 
    }
 
    
       std::string strLine;
       int line = 1;
       while(getline(file,strLine))
       {
 
            if(strLine.empty())
                continue;
 
            //cout<<strLine <<endl;     
			if (line==1&&strLine=="������ģʽ:true")
			{
				getLogger("������ģʽ�ѿ���",1); 
				debug=true; 
			}else{
				getLogger("������ģʽ�ѹر�",1);
				debug=false;
			}
       }
} 

//print
void CommandPrintf(int mode,string filenumber){
	if (mode==1){
		
		string str;
		int a = 0;
		cin>>str;
		
		
		for (int i = 0;i<=PVNumber;i++)
		{
			if (str==PVNameCase[i])
			{
				a = PVCase[i];
				cout<<">>"<<a<<endl;
				return;
			}
		}
		
		cout<<">>"<<str<<endl;
		
	}else if (mode==2){
		int a;
		for (int i = 0;i<=PVNumber;i++)
		{
			if (filenumber==PVNameCase[i])
			{
				//cout<<"��׽��PVNAMECASEֵΪ"<<PVCase[i]<<endl; 
				//cout<<"Iֵ:"<<i<<endl;
				a = PVCase[i-1];
				cout<<">>"<<a<<endl;
				return;
			}
		}
		
		
		cout<<">>"<<filenumber<<endl;
	}
}

//import
void ImportF(int mode)
{
	if(mode==1){
		string modname;
		cin>>modname;
		if (modname=="math")
		{
			if (math==true)
			math=false;
			if (math==false)
			math=true;
		}else{
			error("Fackge CommandManager error","Unknow dlls for fackge",1);
		}
	}else if (mode==2){
			if (math==true)
			math=false;
			if (math==false)
			math=true;
	}
}

void IsPublicVer(string number1,string number2)
{
	bool check1=false;
	bool check2=false;

	int int1 = 0;
	int int2 = 0;
	string str1;
	string str2; 

	for (int i=0;i<=PVNumber;i++)
	{
		if (number1==PVNameCase[i]&&check1==false)
		{
			check1=true;
			int1 = PVCase[i];
			str1=std::to_string(int1);
		}
		if (number2==PVNameCase[i]&&check2==false)
		{
			check2=true;
			int2=PVCase[i];
			str2=std::to_string(int2);
		
		}
	}
	
	if (check1==false)
	{
		str1=number1;
	}
	if (check2==false)
	{
		str2=number2;
	}


	Math1 = stoi(str1);
 
	Math2 = stoi(str2); 
	return;
}

//�߼����� 
void Math(int mode,char ch,int n1,int n2,int line,string ch2)
{
	string number1,number2;
	int x;
	if (mode==1)
	{
		cin>>number1>>ch>>number2;
		
		switch(ch)
		{
			case '+':
				IsPublicVer(number1,number2);
				cout<<">>"<<Math1+Math2<<endl;
				Math1=0;
				Math2=0; 
				break;	
			case '-':
				IsPublicVer(number1,number2);
				cout<<">>"<<Math1-Math2<<endl;
				Math1=0;
				Math2=0;
				break;
			case '*':
				IsPublicVer(number1,number2);
				cout<<">>"<<Math1*Math2<<endl;
				Math1=0;
				Math2=0;
				break;
			case '/':
				IsPublicVer(number1,number2);
				cout<<">>";
				x = Math1/Math2;
				printf("%.3f",x);
				cout<<endl;
				Math1=0;
				Math2=0;
				break;
			default:
				error("Fackge Command Manager error","Unknow type",0);
				return;
				break;
		}
		
		}else if (mode==2)
		{
		if (ch2=="+")
		{
			cout<<">>"<<Math1+Math2<<endl;
			Math1=0;
			Math2=0;
		}else if (ch2=="-")
		{
			cout<<">>"<<Math1-Math2<<endl;
			Math1=0;
			Math2=0;	
		}else if (ch2=="*"){
			cout<<">>"<<Math1*Math2<<endl;
			Math1=0;
			Math2=0;
		}else if (ch2=="/"){
			cout<<">>";
			x = Math1/Math2;
			printf("%.3f",x);
			cout<<endl;
			Math1=0;
			Math2=0;
		}else{
			error("Fackge CommandManager error","Unknow type to fchar[2]",line);
		}
		}else{
			error("Fackge Command Manager error","Unknow type",1);
		}
}

//PublicVer
void PublicVer(int mode,string str1,int str2)
{
	if (mode==1)
	{
		string type;
		char quic;
		cin>>type;
		if (type=="int")
		{
			cin>>PVNameCase[PVNumber];
			cin>>quic;
			cin>>PVCase[PVNumber];
			getLogger("���������ɹ�!",3);
			PVNumber++;
			return;
		}else{
			error("Fackge CommandManager error","Publicver create",1);
		}
	}else if (mode==2)
	{
		PVNameCase[PVNumber] = str1;
		PVCase[PVNumber] = str2;
		
			//cout<<"�ɹ���"<<PVNameCase[PVNumber]<<"�����"<<PVCase[PVNumber]; 
	//	cout<<"Number��"<<PVNumber<<endl; 
		
		PVNumber++;
		return;
	}
}




int main()
{
	sleep(1000);
	getLogger("��ʼ����Fackge",1);
	getLogger("��ʼ��CommandManager�ɹ�!",1); 
	string command;
	bool find = false;
	
	
	//ע������ 
	try{
		
		
		RigCommand("help","��ѯ��������Ͱ���");
		RigCommand("fload","����.f�ű��ļ�");
		RigCommand("printf","��ӡ����");
		RigCommand("import","�����ڲ�ģ��");
		RigCommand("publicver","����һ�����г�Ա����");
		RigCommand("math","�߼�����");
	
	}catch(string){
		throw 0;
	}
	
	
	fstream _file;
	_file.open("fackge.setting",ios::in);
	if(!_file)
	{	
	ofstream inFile; 
	inFile.open("fackge.setting");
	if(inFile.is_open())
	inFile<<"������ģʽ:true"<<endl;
	inFile.close();
	getLogger("��ʼ�������ļ��ɹ�!",1);
	}else{
	//cout<<"��⵽�����ļ��Ѵ���"<<endl;
	getLogger("�����ļ��Ѵ���!",1);
	}
	
	getLogger("��ʼ���������ļ�",1);
	loadconfig();
	
	cout<<"[INFO]��ǰ������ģʽΪ:"<<debug<<endl;
	getLogger("�������",1);
	
	main:
		cout<<"Fakcge>>";
		cin>>command;
		
		//getline(cin,command);
		
		for (int i=0;i<=CommandNumber;i++)
		{
			if (command==CommandManager[i]){
				find = true;
				getLogger("�ҵ���",3);
				i=10000;
			}
		}
		
		if (find==true)
		{
		SendCommand(command,1,0,0);
		find = false; 
		goto main;
		} else {
			getLogger("Unknow command",1);
			find = false;
			goto main;
		}
	

			
		
		
	return 0;
}
