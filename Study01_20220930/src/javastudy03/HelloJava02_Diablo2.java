package javastudy03;

import java.util.Scanner;
import java.util.ArrayList;
public class HelloJava02_Diablo2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		System.out.println("�� ĳ���� �?");
		int count = s.nextInt();
		
		GameCharacter[] players = new GameCharacter[count];
		for(int i= 0; i<players.length; i++) {
			System.out.println(i+1+"��° ĳ���� ������?");
			int lv = s.nextInt();
			if(lv<0) {
				i--;
				continue;
			}
			System.out.println("�� ĳ���� ������?");
			s.nextLine();
			String _class = s.nextLine();
			System.out.println("�� ĳ���� ID��?");
			String id= s.nextLine();
			players[i] = new GameCharacter(id, _class);
			players[i].setLevel(lv);
		}
		for(GameCharacter gameCharacter : players) {
			gameCharacter.printInfo();
		}
		ArrayList<GameCharacter> gamers=
				new ArrayList<GameCharacter>();
		while(gamers.size()!= count) {
			System.out.println("ĳ���� ����?");
			int level =s.nextInt();
			if(level<0)
				continue;
			System.out.println("ĳ��������?");
			s.nextLine();
			String _class = s.nextLine();
			System.out.println("ĳ���� ID?");
			String Id = s.nextLine();
			GameCharacter g = new GameCharacter(Id , _class);
			//gamers.add(new GameCharacter(Id, _class));
			g.setLevel(level);
			gamers.add(g);
			
		}
		for (GameCharacter gameCharacter : gamers) {
			gameCharacter.printInfo();
		}
	}

}
