using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace MyPCRoom
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
            try
            {
                DataGridViewRow dr = dataGridView1.SelectedRows[0]; 
            }
            catch (Exception ex)
            {
              
            }
            //Users 길이가 0 인데,
            //DataSource로 넣으려고 하면 셀 선택시 오류 남
            //셀 : datagridview의 칸들을 의미(엑셀의 셀처럼)
            if (DataManager.Users.Count > 0)
                dataGridView1.DataSource = DataManager.Users;




        }

        private string lookUpParkingSpot(string find_id)
        {
            string find_user_id = "";
            //Single을 써서 특정 공간에 있는 차를 찾을 수도 있다.
            //Single이 부담스럽다면, for문이나 foreach문으로 탐색 가능
            foreach (var item in DataManager.Users)
            {
                if (item.User_id == find_id)
                {
                    find_user_id = item.User_id;
                    break;
                }
            }
            return find_user_id;
        }



        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                PC_User user = DataManager.Users.SingleOrDefault(x => x.User_id == textBox1.Text);
                DataManager.search(user.User_id);

                dataGridView1.DataSource = null;
                if (DataManager.Users.Count > 0)
                {
                    dataGridView1.DataSource = DataManager.Users;
                }
                MessageBox.Show($"'{user.User_id}' 회원이 성공적으로 조회되었습니다.");
            }
            catch (Exception ee)
            {
                MessageBox.Show("해당 회원 없음");
            }

        }


        private void button2_Click_1(object sender, EventArgs e)
        {
            // 초기화
            try
            {
                dataGridView1.DataSource = "";
                DataManager.Load();
            }
            catch (Exception ex)
            {

            }
            //Users 길이가 0 인데,
            //DataSource로 넣으려고 하면 셀 선택시 오류 남
            //셀 : datagridview의 칸들을 의미(엑셀의 셀처럼)
            if (DataManager.Users.Count > 0)
                dataGridView1.DataSource = DataManager.Users;
        }
    }
}
