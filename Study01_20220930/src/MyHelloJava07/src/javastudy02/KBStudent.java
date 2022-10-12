package javastudy02;

public class KBStudent {
	public String Name;
	public String gender;
	public int Age;
	public int Numbaer;

	public String getName() {
		return Name;
	}

	public KBStudent(String name, String gender, int age, int numbaer) {
		super();
		Name = name;
		this.gender = gender;
		Age = age;
		Numbaer = numbaer;
	}

	public void setName(String name) {
		Name = name;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public int getAge() {
		return Age;
	}

	public void setAge(int age) {
		Age = age;
	}

	public int getNumbaer() {
		return Numbaer;
	}

	public void setNumbaer(int numbaer) {
		Numbaer = numbaer;
	}

}
