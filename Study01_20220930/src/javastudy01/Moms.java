package javastudy01;

public class Moms extends Food {

	public Moms(String name, int price) {
		super(name, price);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void eat() {
		// TODO Auto-generated method stub
		super.eat();
		System.out.println(getName() + "�� �ְ��� ����");
		System.out.println(getPrice() + "���� ��������!");

	}

	public void eat(int count) {
		System.out.println("�����Ͽ�" + count + "�� ����");
	}

	public void eat(String side) {
		System.out.println(side + "�� ���̸���");
	}

}
