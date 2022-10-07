package javastudy01;

public class HelloJava03_MomsTouch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Food f = new Food("민초케잌", 20000);
		Food f2 = new Moms("사이버거", 5000);
		Moms f3 = new Moms("갈릭치즈버거", 5500);

		f.eat();
		f2.eat();
		f3.eat();
		if (f2 instanceof Moms) {
			((Moms) f2).eat(3);
		}
		if (f2 instanceof Moms) {
			((Moms) f2).eat("감자튀김");
		}
		f3.eat(5);
		f3.eat("콜라");
	}

}
