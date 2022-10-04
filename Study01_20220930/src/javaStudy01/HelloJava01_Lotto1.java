package javaStudy01;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class HelloJava01_Lotto1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner (System.in);
		System.out.println("얼마너치 살꺼야?");
		int count = s.nextInt()/1000;
		if(count>5 || count<1)
		{
			System.out.println("금액이 잘못되었습니다.");
			return;
		}
		for(int i = 0; i<count; i++)
		{
			ArrayList<Integer> lotto = new ArrayList<Integer>();
			for (int j=0; j<6; j++) {
				int num =(int)(Math.random()*45)+1;
				boolean isDuplicate = false;
				for(int k =0; k<j; k++) {
					if(lotto.get(k)==num) {
						isDuplicate=true;
						j--;
						break;
					}
				}
				if(!isDuplicate)lotto.add(num);
			}
			//System.out.print(lotto.toString());
			int bns= (int)(Math.random()*45)+1;
			for(int j= 0; j<lotto.size(); j++) {
				if(bns==lotto.get(j))
				{
					bns= (int)(Math.random()*45)+1;
					j=-1;
				}
			}
			Collections.sort(lotto);
			System.out.print(lotto.toString());
			System.out.println(" 보너스"+bns);
			//lotto.clear(); lotto안에 있는 값을 전부 삭제(remove)
		}
	}

}
