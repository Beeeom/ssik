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
		System.out.println(getName() + "은 최고의 버거");
		System.out.println(getPrice() + "내고 먹을만해!");

	}

	public void eat(int count) {
		System.out.println("일주일에" + count + "번 먹음");
	}

	public void eat(String side) {
		System.out.println(side + "랑 같이먹음");
	}

}
