package my.hello.javastudy02;

import java.util.ArrayList;

public class JavaStudy02_List_class {

	public static void main(String[] args) {
		//배열, List 모두 숫자만 저장하거나
		//문자열만 저장하는 거 말고
		//객체를 저장하는 것도 된다.
		Student[] students = new Student[3];
		students[0] = new Student();
		students[1] = new Student("이동준",34,1);
		Student s = new Student("박지호",29,2);
		students[2] = s;
		
		//int나 double등으로 변수 선언할 때랑은 다르다.
		//1. new키워드 + 생성자가 있어야지만 객체 생성됨
		//2. 생성자 안에 경우에 따라선 매개변수가 들어가기도 함
		
		ArrayList<Student> mystudents
		= new ArrayList<Student>();
		mystudents.add(new Student("김진규",30,5));
		mystudents.add(new Student());
		Student ss = new Student("도광현",25,4);
		mystudents.add(ss);
		
	}

}



