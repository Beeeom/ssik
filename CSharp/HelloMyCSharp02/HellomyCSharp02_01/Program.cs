using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HellomyCSharp02_01
{
    internal class Program
    {
        private static object kb1;

        public static object Kb1 { get; private set; }

        static void Main(string[] args)
        {
           /* int a = 10;
            string b = "안녕";
            char c = 'A';
            double d = 3.14;
            bool e = false;*/

            Student s1 = new Student();
            s1.Name = "오세룡";
            s1.Age = 20;
            s1.eye = 0.01;

            Student[] students = new Student[3];
            students[0] = s1;
            students[1] = new Student();
            students[1].Name = "박지호";
            students[1].Age = 25;
            students[1].eye = 0.1;

            Console.WriteLine(s1.Name);
            Console.WriteLine(students[1].Name);

            Student stu1 = new Student();
            stu1.Name = "이범식";
            stu1.Age = 41;
            stu1.eye = 0.6;
            Console.WriteLine($"{stu1.Name}학생은"+$"{stu1.Age}살이고, 시력은{stu1.eye}이다.");

            Student stu2 = new Student();
            Console.WriteLine("이름은?");
            stu2.Name = Console.ReadLine();
            stu2.Age = int.Parse(Console.ReadLine());
            Console.WriteLine("시력은?");
            stu2.eye = double.Parse(Console.ReadLine());
            Console.WriteLine($"{stu2.Name}학생은 " + $"{stu2.Age}살이고, 시력은 {stu2.eye}입니다.");

            Student[] stus = new Student[3];
            stus[0] = new Student();
            stus[0].Name = "조영탁";
            stus[0].Age = 30;
            stus[0].eye = 1.2;
            stus[1] = new Student();
            stus[1].Name = "오세룡";
            stus[1].Age = 25;
            stus[1].eye = 0.3;
            stus[2] = new Student();
            stus[2].Name = "박재형";
            stus[2].Age = 25;
            stus[2].eye = 0.6;

            for(int i =0; i<stus.Length; i++)
            {
                Console.WriteLine($"{stus[i].Name}학생은" +$"{stus[i].Age}살이고, 시력은 {stus[i].eye}이다.");
            }

            Student[] stus2 = new Student[3];
            for(int i=0; i<stus2.Length; i++)
            {
                stus2[i] = new Student();
                Console.WriteLine("이름은??");
                stus2[i].Name = Console.ReadLine();
                Console.WriteLine("나이???");
                stus2[i].Age = int.Parse(Console.ReadLine());
                Console.WriteLine("시력??");
                stus2[i].eye = double.Parse(Console.ReadLine());

                Console.WriteLine("이름 :" + stus2[i].Name);
                Console.WriteLine("나이 :" + stus2[i].Age);
                Console.WriteLine("시력 :" + stus2[i].eye.ToString("0.0"));

                Console.WriteLine("KB 학생 만들기!");
                KBStudent kb1 = new KBStudent();
                kb1.Name = "장혜정";
                kb1.Age = 20;
                kb1.eye = 1.5;
                kb1.MBTI = "ISFP";

                Console.WriteLine("이름 :" + kb1.Name);
                Console.WriteLine("나이 :" + kb1.Age);
                Console.WriteLine("시력 :" + kb1.eye);
                Console.WriteLine("MBTI :" + kb1.MBTI);


                KBStudent kb2 = new KBStudent();
                kb2.Name = "김성환";
                kb2.Age = 20;
                kb2.eye = 1.7;
                kb2.MBTI = "ENFP";
                kb2.introduce();
            }
        }
    }
}
