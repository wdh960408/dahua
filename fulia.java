package fuli;

public class fulia {
	 public static void main(String[] args){ 
	  double money = 1000;  //���� 
	  int years = 20;    //��Ǯ���� 
	  double sum = 0;  //����ܶ� 
	  double r = 0.05;   //���� 
	  for(int i = 1 ; i<=years; i++){ 
	   sum = (1+ r) * i *money;  
	   System.out.println("�����"+i+"���Ĵ���ܶ�Ϊ��"+sum); 
	  } 
	 } 
	}


