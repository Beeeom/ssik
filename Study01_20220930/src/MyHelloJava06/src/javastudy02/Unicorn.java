package javastudy02;

public class Unicorn extends Cryptid implements Fliable, Runsable {

	@Override
	public void Run() {
		// TODO Auto-generated method stub
		System.out.println("´Ù±×´Ú´Ù±×´Ú");
	}

	@Override
	public void jog() {
		// TODO Auto-generated method stub
		System.out.println("´À¸´´À¤Ë¤Ë¤Ë¤Ë");
	}

	@Override
	public void Fly() {
		// TODO Auto-generated method stub
		System.out.println("¿ì¾ÆÇÏ°Ô ³³´Ï´Ù");
	}

	@Override
	public void FlapWing() {
		// TODO Auto-generated method stub
		System.out.println("ÆÛ´öÆÛ´ö");
	}

	@Override
	public void sleep() {
		// TODO Auto-generated method stub
		System.out.println("ÀáÀ» ÀÚÁö ¾Ê¾Æ¿ä~");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
