package codingtest;

import java.util.Scanner;

public class Solve {
//1
	public static void main(String[] args) {

		int sum = 0;
		for (int i = 3; i <= 8; i++) {
			if (i % 2 != 0)
				sum += i;
		}
		System.out.println(sum);
//2
		Scanner s = new Scanner(System.in);
		String sentense = s.nextLine();
		for (int i = sentense.length() - 1; i >= 0; i--)
			System.out.print(sentense.charAt(i));
//3
		// 배경지식: 1byte = 8bit
		System.out.println("\n몇 바이트?");
		try {
			int num = s.nextInt();
			System.out.println(num + "바이트=" + (num * 8) + "비트");
		} catch (Exception e) {
			System.out.println("값을 잘못 입력함");
		}
	}
}
