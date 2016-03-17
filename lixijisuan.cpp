#include<stdio.h>
#include<math.h>

double danli(double i,int N,double P)
{
    double nlx,F;
    nlx = P*i;
    F = nlx*N + P;
    return F;

}

double fuli(double i,int W,int N,double P)
{
    double F;
    i=pow(1+i/W,W)-1;
    F=P*pow((i+1),N);
    return F;
}

double gusuan(double i,int W,int N,double F)
{
    double P;
    i = pow(1+i/W,W)-1;
    P = F/pow((i+1),N);
    return P;
}
double shijian(double P,double i,double F)
{
    double N,x;
    x=F/P;
    N=(log(x))/(log(i+1));
    return N;

}
double nianxian(double P,double N,double F)
{
    double i;
     //i = W*(pow(pow(F/P,1.0/N),1.0/W)-1.0);
     i = pow(F/P,1.0/N)-1.0;
     return i;
}
void main()
{
    double P,F1,F,i; //P是本金，F是收益，i年利率
    int N,W,ch2; //是期限
    while(1)
    {
    printf("\t\t***************欢迎使用复利计算器*************\n\n");
    printf("\t\t|     -----1:复利---------------    |\n\n");
    printf("\t\t|     -----2:单利---------------    |\n\n");
    printf("\t\t|     -----3:估算----------------    |\n\n");
    printf("\t\t|     -----4:年限----------------    |\n\n");
    printf("\t\t|     -----5:年利率--------------    |\n\n");
    printf("\t\t|     -----0:退出----------------    |\n\n");
    printf("请选择\n");
    scanf("%d",&ch2);//控制选择
    switch(ch2){
    case 1:
        printf("请输入本金：\n");
        scanf("%lf",&P);
        printf("请输入年利率\n");
        scanf("%lf",&i);
        printf("请输入年限：\n");
        scanf("%d",&N);
        printf("请输入复利次数：\n");
        scanf("%d",&W);
        F1 = fuli(i,W,N,P); break;
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

    case 0:break;
    }
    if(ch2==0)
        break;
    printf("结果为：%.2lf\n",F1);
    }
}