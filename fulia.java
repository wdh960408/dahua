package fuli;

public class fulia {
	 public static void main(String[] args){ 
	  double money = 1000;  //本金 
	  int years = 20;    //存钱年数 
	  double sum = 0;  //存款总额 
	  double r = 0.05;   //利率 
	  for(int i = 1 ; i<=years; i++){ 
	   sum = (1+ r) * i *money;  
	   System.out.println("存入第"+i+"年后的存款总额为："+sum); 
	  } 
	 } 
	}


