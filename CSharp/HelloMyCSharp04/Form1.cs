using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloMyCSharp04
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a = 5;
            int b = 10;
            int c = 0;
            c = a + b;
            c = c - a;
            Console.WriteLine(c = c -a);
            Console.WriteLine(a);
            Console.WriteLine(c = c - a);
            Console.WriteLine(c = c - a);
            Console.WriteLine(c = c - a);
            Console.WriteLine(c = c - a);
            Console.WriteLine("안녕하세요");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (char i = '가'; i <= '힣'; i++)
            {
                Console.Write(i);
            }

        }
    }
}
