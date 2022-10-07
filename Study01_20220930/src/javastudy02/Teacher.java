package javastudy02;

public abstract class Teacher {
	public String Name;
	public String major;

	public String getName() {
		return Name;
	}

	public void setName(String name) {
		Name = name;
	}

	public String getMajor() {
		return major;
	}

	public void setMajor(String major) {
		this.major = major;
	}

	public abstract void Teacher();
}
