#include<stdio.h>
#include<math.h>
void touzi();

void bijiao(int q,double number[4]);

double danli(double i,int N,double P)//单利计算
{
double nlx,F;
nlx = P*i;
F = nlx*N + P;
return F;

}

double fuli(double i,int W,int N,double P)//复利计算
{
double F;
i=pow(1+i/W,W)-1;
F=P*pow((i+1),N);
return F;
}

double gusuan(double i,int W,int N,double F)//估算
{
double P;
i = pow(1+i/W,W)-1;
P = F/pow((i+1),N);
return P;
}
double shijian(double P,double i,double F)//时间
{
double N,x;
x=F/P;
N=(log(x))/(log(i+1));
return N;

}
double nianxian(double P,double N,double F)//年限
{
double i;
i = pow(F/P,1.0/N)-1.0;
return i;
}
double sum()
{
double y,yue,F=0.0,i,mi;
double nl,yl;
int N;
int ch,j;
printf("****** 1-年投资 2-月投资 ******\n");
scanf("%d",&ch);
if(ch == 1)
{
printf("请输入年投资额：\n");
scanf("%lf",&y);
}
else
{
printf("请输入月投资额：\n");
scanf("%lf",&yue);
}

printf("请输入年利率\n");
scanf("%lf",&i);
printf("请输入年限\n");
scanf("%d",&N);

if(ch == 1)
{
F = y;
for(j=0 ; j<N ; j++)
{
nl = F*i;
F=y+nl+F;
}
return F-y;
}
else
{
F = yue;
mi = i/12.0;
for(j=0 ; j<N*12 ; j++)
{
yl = F*mi;
F=yue+yl+F;
}
return F-yue;
}


}
double refund()
{
double P,i,month_amount;
int N,month;
printf("************您进入本息还款计算************\n");
printf("请输入贷款金额：\n");
scanf("%lf",&P); 
printf("请输入年利率：\n");
scanf("%lf",&i); 
printf("请输入归还年限：\n");
scanf("%d",&N); 

//每月还款额=[贷款本金×月利率×（1+月利率）^还款月数]÷[（1+月利率）^还款月数－1]

i = i/12;
month = N*12;
month_amount = P*i*pow((1.0+i),month)/(pow(1.0+i,month)-1);
return month_amount;

}
void main()
{
double P,F1,F,i; //P是本金，F是收益，i年利率
int N,W,ch2; //是期限
while(1)
{
printf("\t\t*****欢迎使用复利计算器****\n\n");
printf("\t 1:~~~~~复利~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 2:~~~~~单利~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 3:~~~~~估算~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 4:~~~~~年限~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 5:~~~~~年利率~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 6:~~~~~月年收益~~~~~~~~~~~~~~ |\n\n");
printf("\t 7:~~~~~等额本息还款~~~~~~~~~~ |\n\n");
printf("\t 8:~~~~~投资计算~~~~~~~~~~~~~~ |\n\n");
printf("\t 0:~~~~~为退出~~~~~~~~~~~~~~~~ |\n\n");
printf("\t**************请选择想要的功能************\n");
scanf("%d",&ch2);//控制选择
switch(ch2){
case 1:
printf("请输入本金：\n");
scanf("%lf",&P);
case 2:
printf("请输入本金：\n");
scanf("%lf",&P);
printf("请输入年利率\n");
scanf("%lf",&i);
printf("请输入年限：\n");
scanf("%d",&N);
F1 = danli(i,N,P); break;
case 3:
printf("请输入本利\n");
scanf("%lf",&F);
printf("请输入年利率\n");
scanf("%lf",&i);
printf("请输入年限：\n");
scanf("%d",&N);
printf("请输入复利次数：\n");
scanf("%d",&W);
F1 = gusuan(i,W,N,F);
break;

case 4:
printf("请输入本金\n");
scanf("%lf",&P);
printf("请输入年利率\n");
scanf("%lf",&i);
printf("请输入本利\n");
scanf("%lf",&F);
F1=shijian(P,i,F);
break;
case 5:

printf("请输入本金：\n");
scanf("%lf",&P);
printf("请输入本利：\n");
scanf("%lf",&F);
printf("请输入年限\n");
scanf("%d",&N);
F1=nianxian(P,N,F);

break;
case 6:
F1=sum();
break;
case 7:
F1=refund();
break;
case 8:
touzi();
case 0:break;
default:
printf("输入不合法！！\n");
continue ;
}
if(ch2==0)
break;
printf("结果为：%.2lf\n",F1);
}
}
void touzi()//计算

{

int n,q=0;

double i,p;

double temp;

double number[4];

printf("\t*请输入存储金额:");

while(scanf("%lf",&p)!=1||p<=0)

{

printf("\t输入错误，请重新输入:");

getchar();

}

printf("\t*请输入年利率:");

while(scanf("%lf",&i)!=1||i<=0)

{

printf("\t输入错误，请重新输入:");

getchar();

} 
printf("\t*请输入t投资时间(年):");

while(scanf("%d",&n)!=1||n<=0||n>100)

{

printf("\t输入错误，请重新输入:");

getchar();

}
number[0]=p*pow((1+i),n);//复利

bijiao(0,number);

number[1]=p*12*(pow(1+i,n)-1)/i;//等额月投

bijiao(1,number);

number[2]=(p*pow((1+i),n)-1)/i;//等额年投

bijiao(2,number);

number[3]=p*(1+i*n);//单利

bijiao(3,number);

temp=number[0];

for(int j=1;j<4;j++)

{
if(number[j]>temp)

{
temp=number[j];

q=j;
}

}
printf("\t建议:\n");

bijiao(q,number);
}

void bijiao(int q,double number[4])//判断最大的利益投资

{
switch (q)

{
case 0:printf("\t选择复利投资,本利和为%.2lf\n",number[0]);break;

case 1:printf("\t选择等额月投资,本利和为%.2lf\n",number[1]);break;

case 2:printf("\t选择等额年投资,本利和为%.2lf\n",number[2]);break;

case 3:printf("\t选择等单利投资,本利和为%.2lf\n",number[3]);break;

}
}