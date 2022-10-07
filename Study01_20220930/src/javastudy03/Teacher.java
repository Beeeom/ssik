package javastudy03;

public abstract class Teacher {
	private String name;
	private String Major;

	public abstract void Teach();

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getMajor() {
		return Major;
	}

	public void setMajor(String major) {
		Major = major;
	}
}
