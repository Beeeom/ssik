using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloMyCSharp03
{
    public partial class SubForm : Form
    {
        public SubForm()
        {
            InitializeComponent();
            label_output.Text = "0";
            Button b1 = new CircularButton();
            b1.Size = new System.Drawing.Size(100, 100);
            b1.Location = new Point(200,10);
            b1.Text = "첫번째 원";
            CircularButton b2 = new CircularButton();
            b2.Size = new System.Drawing.Size(100, 100);
            b2.Location = new Point(100, 100);
            b2.Text = "두번째 원";
            Controls.Add(b1);
            Controls.Add(b2);
        }
        public SubForm(string txt)
        {
            InitializeComponent();
            label_output.Text = 
                $"{txt}님 환영합니다.";
        }
    }
}
