package javastudy02;

import java.util.ArrayList;

public class HelloJava01_sikdang {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Food f = new Food()
		Food f = new Taco();
		Ramen r = new Ramen();
		Bibimbab b = new Bibimbab();

		f.eat();
		r.eat();
		b.eat();

		ArrayList<Food> foods = new ArrayList<Food>();
		foods.add(f);
		foods.add(r);
		foods.add(b);
		for (Food food : foods) {
			food.eat();
		}
	}

}
