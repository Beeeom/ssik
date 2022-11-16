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
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void button_mbox_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Input.Text+"를 입력하셨습니다.");
        }

        private void Input_TextChanged(object sender, EventArgs e)
        {
        }

        private void button_customized_Click(object sender, EventArgs e)
        {
            SubForm s = new SubForm(Input.Text);
            s.Show();
        }

        private void button_show_Click(object sender, EventArgs e)
        {
            SubForm s = new SubForm();
            s.Show();
        }
    }
}
