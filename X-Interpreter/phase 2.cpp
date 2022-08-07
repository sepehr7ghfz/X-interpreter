/*
Yasamin Azimi
Sepehr Ghaffarzadegan
Armin Zare
*/


#include <iostream>
#include<string.h>
#include<string>
#include<sstream>
#include<conio.h>
#include<cctype>
#include<stdio.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

int novar=0;
string args1 , args , cmd;

int starter(string input);
string parser1(string input)
{
    while(input[0]==' ')
        input.erase(0,1);
    string ret;
    int j = 0,k = 0;

    for(int i = 0;i < input.size();i++)
    {
            //if(input[i] == ' ' && i==0) rize error
            if(input[i] == ' ')
            {
                if(k == 0)
                    k++;
                else
                    continue;
            }

            //if(isnumber(input[i]) && i == 0) rize error;
            //if(input[i] = & $ ,...) rize error

            ret+=input[i];
            j++;

    }

    return ret;
}
struct input
{
    string varname;
    double varval;
    bool type ; // real=0 int=1
} varrec[1000];

void strtoupper(string &input)
{
    for(int i=0;i<input.size();i++)
        input[i]=toupper(input[i]);
}
void INT(string arg)
{
    if(arg.size()>=8){
        cout<<"Error : Too Many Characters"<<endl;
        return ;
    }
    for(int i=0;i<args.size();i++){
      if(isalpha(arg[i]));
    else
        cout<<"Error : Invalid Input"<<endl;

    }
    varrec[novar].varname=arg;
    varrec[novar].type=1;
    novar++;
    }
void REAL(string arg)
{
    if(arg.size()>=8){
    cout<<"Error : Too Many Characters"<<endl;
    return ;
    }
    for(int i=0;i<args.size();i++){
      if(isalpha(arg[i]));
    else
        cout<<"Error : Invalid Input"<<endl;
    }
    varrec[novar].varname=arg;
    varrec[novar].type=0;
    novar++;
}
void ASSIGN(string var,string num)
{
    if(num==""){
        cout<<"Error : Insert a Value"<<endl;
        return;
    }
    else {
    double adad;
    for(int i=0;i<novar;i++)
    {
        if(varrec[i].varname==var)
        {
        adad = atof(num.c_str());
            if(varrec[i].type==1 && adad ==(int) adad )
                varrec[i].varval = adad;
            else
                cout<<"Error : Invalid Value"<<endl;
            break;
        }
        else
            cout<<"Error : Invalid Variable"<<endl;
    }
    }
}
void READ(string var)
{
    for(int j=0;j<var.size();j++)
    {
        if(var[j]==',')
        {
        cout<<"Error : Invalid Input"<<endl;
        return;
        }
    }

    cout<<"?"<<endl;
    double adad;
    int flag2 = 0;
    string adad2;
    getline(cin,adad2);

    for(int i=0; i<novar ;i++)
    {
        if(varrec[i].varname==var)
        {
         flag2=i;
         break;
        }
    }
    adad = atof(adad2.c_str());
    if(varrec[flag2].type && (int)adad==adad)
    {
    for(int i=0;i<novar;i++)
    {
        if(varrec[i].varname==var)
        {
            if(varrec[i].type==1)
                varrec[i].varval =(int) adad;
            else
                 varrec[i].varval= adad ;
            break;
        }
    }
    }
    else
    {
        cout<<"Error : Invalid Input"<<endl;
        return;
    }
}
void PRINT(string var)
{
    int flag=0;
if(args[0]=='"'&&args[args.size()-1]=='"')
{
    args1 =args1.erase(0,1);
    args1 = args1.erase(args.size()-2,1);
    cout << args1 << endl;
}
else
{
int i;
for(i=0;i<novar && flag == 0;i++)
{

    if( var == varrec[i].varname)
        flag+=1;

}
    if(flag==0)
        cout<<"Error : Invalid Input "<<endl;
    else
        cout<<varrec[i-1].varval<<endl;
   }

}
int findVarrec(string a){
    int check=-1;
    for(int i=0;i<novar;i++){
        if(varrec[i].varname==a){
            check=i;
            break;
        }
    }
    return check;
}
void ADD(string var)
{
    int tedad_virgul = 0;
    for(int i = 0; i < var.size(); i++)
        if(var[i] == ',')
            tedad_virgul++;
    if(tedad_virgul !=2)
    {
        cout << "Error: Invalid Input " << endl;
        return;
    }

    int virgol1=var.find(',');
    string num1=var.substr(0,virgol1);
    var[virgol1]='s';
    int virgol2=var.find(',');
    var[virgol1]=',';
    string num2=var.substr(virgol1+1,virgol2-virgol1-1);
    string num3=var.substr(virgol2+1,var.size()-virgol2-1);
    bool ceck=true;
    if(num1.size() == 0 || num2.size() == 0 || num3.size() == 0)
    {
        cout <<"Error"<<endl;
        return;
    }
    if(findVarrec(num1)==-1){
        cout <<"Error : Invalid Variable\n";
    }
    else{
        double result2;
        istringstream convert(num2);
        if ( !(convert >> result2) ){
            int makan=findVarrec(num2);
            if(makan!=-1){
                result2=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }

        double result3;
        istringstream convert2(num3);
        if ( !(convert2 >> result3) )
            {
            int makan=findVarrec(num3);
            if(makan!=-1){
                result3=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        int makan =findVarrec(num1);
        varrec[makan].varval= (int) (result3+result2);
    }
}
void DIVI(string var)
{
    int tedad_virgul = 0;
    for(int i = 0; i < var.size(); i++)
        if(var[i] == ',')
            tedad_virgul++;
    if(tedad_virgul !=2)
    {
        cout << "Error : Invalid Input " << endl;
        return;
    }
    int virgol1=var.find(',');
    string num1=var.substr(0,virgol1);
    var[virgol1]='s';
    int virgol2=var.find(',');
    var[virgol1]=',';
    string num2=var.substr(virgol1+1,virgol2-virgol1-1);
    string num3=var.substr(virgol2+1,var.size()-virgol2-1);
    if(findVarrec(num1)==-1){
        cout <<"Error : Invalid Variable\n";
    }
    else{
        double result2;
        istringstream convert(num2);
        if ( !(convert >> result2) ){
            int makan=findVarrec(num2);
            if(makan!=-1){
                result2=varrec[makan].varval;
            }
            else
                cout <<"Error : Invalid Variable\n";
        }

        double result3;
        istringstream convert2(num3);
        if ( !(convert2 >> result3) )
            {
            int makan=findVarrec(num3);
            if(makan!=-1){
                result3=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        int makan =findVarrec(num1);
        if((int) result2==result2 &&(int) result3==result3 && varrec[makan].type==1){
        varrec[makan].varval= (int) result2  /  (int) result3 ;
        cout<<varrec[makan].varval<<endl;
        }
        else
            cout<<"Error : Invalid Input"<<endl;
    }
}
void DIVR(string var)
{
    int virgol1=var.find(',');
    string num1=var.substr(0,virgol1);
    var[virgol1]='s';
    int virgol2=var.find(',');
    var[virgol1]=',';
    string num2=var.substr(virgol1+1,virgol2-virgol1-1);
    string num3=var.substr(virgol2+1,var.size()-virgol2-1);
    bool ceck=true;

    if(findVarrec(num1)==-1){
        cout <<"Error : Invalid Variable\n";
    }
    else{
        double result2;
        istringstream convert(num2);
        if ( !(convert >> result2) ){
            int makan=findVarrec(num2);
            if(makan!=-1){
                result2=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }

        double result3;
        istringstream convert2(num3);
        if ( !(convert2 >> result3) )
            {
            int makan=findVarrec(num3);
            if(makan!=-1){
                result3=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        int makan =findVarrec(num1);
        varrec[makan].varval= ( result2  /   result3 ) ;
        cout<<varrec[makan].varval<<endl;
    }
}
void MULT(string var)
{
    int virgol1=var.find(',');
    string num1=var.substr(0,virgol1);
    var[virgol1]='s';
    int virgol2=var.find(',');
    var[virgol1]=',';
    string num2=var.substr(virgol1+1,virgol2-virgol1-1);
    string num3=var.substr(virgol2+1,var.size()-virgol2-1);
    bool ceck=true;

    if(findVarrec(num1)==-1){
        cout <<"Error : Invalid Variable\n";
    }
    else{
        double result2;
        istringstream convert(num2);
        if ( !(convert >> result2) ){
            int makan=findVarrec(num2);
            if(makan!=-1){
                result2=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        double result3;
        istringstream convert2(num3);
        if ( !(convert2 >> result3) )
            {
            int makan=findVarrec(num3);
            if(makan!=-1){
                result3=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        int makan =findVarrec(num1);
        varrec[makan].varval=(int) (result3*result2);
        cout<<varrec[makan].varval<<endl;
    }
}
void SUB(string var)
{
    int virgol1=var.find(',');
    string num1=var.substr(0,virgol1);
    var[virgol1]='s';
    int virgol2=var.find(',');
    var[virgol1]=',';
    string num2=var.substr(virgol1+1,virgol2-virgol1-1);
    string num3=var.substr(virgol2+1,var.size()-virgol2-1);
    bool ceck=true;

    if(findVarrec(num1)==-1){
        cout <<"Error : Invalid Variable\n";
    }
    else{
        double result2;
        istringstream convert(num2);
        if ( !(convert >>  result2) ){
            int makan=findVarrec(num2);
            if(makan!=-1){
                result2=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
         double result3;
        istringstream convert2(num3);
        if ( !(convert2 >>  result3) )
            {
            int makan=findVarrec(num3);
            if(makan!=-1){
                result3=varrec[makan].varval;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        int makan =findVarrec(num1);
        varrec[makan].varval=(int) (result2-result3);
        cout<<varrec[makan].varval<<endl;
    }
}
void MOD(string var)
{
    int virgol1=var.find(',');
    string num1=var.substr(0,virgol1);
    var[virgol1]='s';
    int virgol2=var.find(',');
    var[virgol1]=',';
    string num2=var.substr(virgol1+1,virgol2-virgol1-1);
    string num3=var.substr(virgol2+1,var.size()-virgol2-1);
    bool ceck=true;

    if(findVarrec(num1)==-1){
        cout <<"Error :Invalid Variable\n";
    }
    else{
         double result2;
        istringstream convert(num2);
        if ( !(convert >>      result2) ){
            int makan=findVarrec(num2);
            if(makan!=-1){
               ( result2=varrec[makan].varval) ;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
       double result3;
        istringstream convert2(num3);
        if ( !(convert2 >>   result3) )
            {
            int makan=findVarrec(num3);
            if(makan!=-1){
               ( result3=varrec[makan].varval) ;
            }
            else{
                cout <<"Error : Invalid Variable\n";
            }
        }
        int makan =findVarrec(num1);
        varrec[makan].varval= ((int)  result2 % (int)  result3);
        cout<<varrec[makan].varval<<endl;
    }
}
void RUNF(string file2)
{
    ifstream file1;
    file1.open(("C:\\Users\\sepehr-gh\\Desktop\\c++\\X-Interpreter\\" +file2).c_str() , ios::in);
    string a;
 if(file1.is_open())
  while(!file1.eof())
    {
        a="";
        getline(file1,a);
       if(starter(a)==0)
        return;
    }
  else
        cout<<"file doesn't exist"<<endl;
}int starter(string input)
{
        int j=0;
 input=parser1(input);

        cmd="";

        while(input[j]!=' ')

              cmd+=input[j++];

        j++;

        strtoupper(cmd);

        args="";

        args1="";

        while(j<input.size())

            args+=input[j++];

        args1=args;

        strtoupper(args);

        if(input=="END" || input=="end")

            return 0;

        if(args!=""){

         if(cmd =="INT")

            INT(args);

        else if(cmd =="REAL")

            REAL(args);

        else if(cmd =="ASSIGN")

        {

            int pos = args.find(',');

            if (pos>=1){

            string assignn= args.substr(0,pos);

            string adad=  args.substr(pos+1,args.size());

            ASSIGN(assignn,adad);}

            else cout<<"Syntax Error"<<endl;

        }

        else if(cmd =="ADD")

            ADD(args);

        else if(cmd =="READ")

            READ(args);

         else if(cmd =="PRINT")

             PRINT(args);

         else if(cmd =="SUB")

            SUB(args);

         else if(cmd =="MULT")

            MULT (args);

          else if(cmd =="MOD")

            MOD (args);

          else if(cmd =="DIVI")

            DIVI(args);

          else if(cmd =="DIVR")

            DIVR(args);

           else if(cmd =="RUNF")
            RUNF(args);

         else cout<<"Error : Invalid Command "<<endl;

        }

        else cout<<"Syntax Error"<<endl;







return 2;


}
int main()
{
        while(true){

        string input;
        cout<<"->";
        getline(cin,input);


        if(starter(input)==0)
            return 0;
        }
}
