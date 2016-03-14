package fuli;

public class fuli {
	 public static void main(String[] args){ 
	  int years = 30;
	  double sum = 0;   
	  double r = 0.03;
	  double money=100000;
		for(int i=0;i<years;i++){
	  sum=money*i*r+money;
	   System.out.println("存入第"+i+"年后的存款总额为："+sum); 
	  } 
	 } 
}


