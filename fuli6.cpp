#include<stdio.h>
#include<math.h>
void touzi();

void bijiao(int q,double number[4]);

double danli(double i,int N,double P)//��������
{
double nlx,F;
nlx = P*i;
F = nlx*N + P;
return F;

}

double fuli(double i,int W,int N,double P)//��������
{
double F;
i=pow(1+i/W,W)-1;
F=P*pow((i+1),N);
return F;
}

double gusuan(double i,int W,int N,double F)//����
{
double P;
i = pow(1+i/W,W)-1;
P = F/pow((i+1),N);
return P;
}
double shijian(double P,double i,double F)//ʱ��
{
double N,x;
x=F/P;
N=(log(x))/(log(i+1));
return N;

}
double nianxian(double P,double N,double F)//����
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
printf("****** 1-��Ͷ�� 2-��Ͷ�� ******\n");
scanf("%d",&ch);
if(ch == 1)
{
printf("��������Ͷ�ʶ\n");
scanf("%lf",&y);
}
else
{
printf("��������Ͷ�ʶ\n");
scanf("%lf",&yue);
}

printf("������������\n");
scanf("%lf",&i);
printf("����������\n");
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
printf("************�����뱾Ϣ�������************\n");
printf("����������\n");
scanf("%lf",&P); 
printf("�����������ʣ�\n");
scanf("%lf",&i); 
printf("������黹���ޣ�\n");
scanf("%d",&N); 

//ÿ�»����=[�����������ʡ���1+�����ʣ�^��������]��[��1+�����ʣ�^����������1]

i = i/12;
month = N*12;
month_amount = P*i*pow((1.0+i),month)/(pow(1.0+i,month)-1);
return month_amount;

}
void main()
{
double P,F1,F,i; //P�Ǳ���F�����棬i������
int N,W,ch2; //������
while(1)
{
printf("\t\t*****��ӭʹ�ø���������****\n\n");
printf("\t 1:~~~~~����~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 2:~~~~~����~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 3:~~~~~����~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 4:~~~~~����~~~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 5:~~~~~������~~~~~~~~~~~~~~~~ |\n\n");
printf("\t 6:~~~~~��������~~~~~~~~~~~~~~ |\n\n");
printf("\t 7:~~~~~�ȶϢ����~~~~~~~~~~ |\n\n");
printf("\t 8:~~~~~Ͷ�ʼ���~~~~~~~~~~~~~~ |\n\n");
printf("\t 0:~~~~~Ϊ�˳�~~~~~~~~~~~~~~~~ |\n\n");
printf("\t**************��ѡ����Ҫ�Ĺ���************\n");
scanf("%d",&ch2);//����ѡ��
switch(ch2){
case 1:
printf("�����뱾��\n");
scanf("%lf",&P);
case 2:
printf("�����뱾��\n");
scanf("%lf",&P);
printf("������������\n");
scanf("%lf",&i);
printf("���������ޣ�\n");
scanf("%d",&N);
F1 = danli(i,N,P); break;
case 3:
printf("�����뱾��\n");
scanf("%lf",&F);
printf("������������\n");
scanf("%lf",&i);
printf("���������ޣ�\n");
scanf("%d",&N);
printf("�����븴��������\n");
scanf("%d",&W);
F1 = gusuan(i,W,N,F);
break;

case 4:
printf("�����뱾��\n");
scanf("%lf",&P);
printf("������������\n");
scanf("%lf",&i);
printf("�����뱾��\n");
scanf("%lf",&F);
F1=shijian(P,i,F);
break;
case 5:

printf("�����뱾��\n");
scanf("%lf",&P);
printf("�����뱾����\n");
scanf("%lf",&F);
printf("����������\n");
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
printf("���벻�Ϸ�����\n");
continue ;
}
if(ch2==0)
break;
printf("���Ϊ��%.2lf\n",F1);
}
}
void touzi()//����

{

int n,q=0;

double i,p;

double temp;

double number[4];

printf("\t*������洢���:");

while(scanf("%lf",&p)!=1||p<=0)

{

printf("\t�����������������:");

getchar();

}

printf("\t*������������:");

while(scanf("%lf",&i)!=1||i<=0)

{

printf("\t�����������������:");

getchar();

} 
printf("\t*������tͶ��ʱ��(��):");

while(scanf("%d",&n)!=1||n<=0||n>100)

{

printf("\t�����������������:");

getchar();

}
number[0]=p*pow((1+i),n);//����

bijiao(0,number);

number[1]=p*12*(pow(1+i,n)-1)/i;//�ȶ���Ͷ

bijiao(1,number);

number[2]=(p*pow((1+i),n)-1)/i;//�ȶ���Ͷ

bijiao(2,number);

number[3]=p*(1+i*n);//����

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
printf("\t����:\n");

bijiao(q,number);
}

void bijiao(int q,double number[4])//�ж���������Ͷ��

{
switch (q)

{
case 0:printf("\tѡ����Ͷ��,������Ϊ%.2lf\n",number[0]);break;

case 1:printf("\tѡ��ȶ���Ͷ��,������Ϊ%.2lf\n",number[1]);break;

case 2:printf("\tѡ��ȶ���Ͷ��,������Ϊ%.2lf\n",number[2]);break;

case 3:printf("\tѡ��ȵ���Ͷ��,������Ϊ%.2lf\n",number[3]);break;

}
}