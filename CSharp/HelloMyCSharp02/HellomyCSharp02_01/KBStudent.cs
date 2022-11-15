using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HellomyCSharp02_01
{
    internal struct KBStudent
    {
        public string Name;
        public double eye;
        public int Age;
        public string MBTI;

        public void introduce()
        {
            Console.WriteLine("이름 :" + Name);
            Console.WriteLine("시력 :" + eye);
            Console.WriteLine("나이 :" + Age);
            Console.WriteLine("MBTI :" + this.MBTI);
        }
    }
}
