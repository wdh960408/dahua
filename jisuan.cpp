#include<stdio.h>
#include<math.h>
#define x1
#define x2
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
       printf("****** 1-��Ͷ��  2-��Ͷ�� ******\n");
       scanf("%d",&ch);
      if(ch == 1)
      {
           printf("��������Ͷ�ʶ\n");
         scanf("%lf",&y)  x2;
       }
       else
       {
           printf("��������Ͷ�ʶ\n");
            scanf("%lf",&yue)  x2;
       }
       
       printf("������������\n");
         scanf("%lf",&i)  x2;
       printf("����������\n");
        scanf("%d",&N)  x2;
       
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
      printf("\t\t***************��ӭʹ�ø���������*************\n\n");
      printf("\t\t|     -----1:����----------------    |\n\n");
      printf("\t\t|     -----2:����----------------    |\n\n");
     printf("\t\t|     ------3:����----------------    |\n\n");
    printf("\t\t|     -------4:����----------------    |\n\n");
     printf("\t\t|     ------5:������--------------    |\n\n");
     printf("\t\t|     ------6:��������------------    |\n\n");
     printf("\t\t|     ------7:�ȶϢ����--------    |\n\n");
     printf("\t\t|     ------0:Ϊ�˳�----------------  |\n\n");
     printf("\t\t**************��ѡ����Ҫ�Ĺ���************\n");
     x1  scanf("%d",&ch2)  x2;//����ѡ��
     switch(ch2){
     case 1:
         printf("�����뱾��\n");
          scanf("%lf",&P);
         printf("������������\n");
          scanf("%lf",&i);
         printf("���������ޣ�\n");
         scanf("%d",&N);
         printf("�����븴��������\n");
         scanf("%d",&W);
         F1 = fuli(i,W,N,P); break;
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