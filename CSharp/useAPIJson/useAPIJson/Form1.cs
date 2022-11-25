using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace useAPIJson
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            lottoBindingSource.Clear();
            int.TryParse(textBox1.Text, out int count);
            if(count<1)
                count = 1;
            while (true)
            {
                using (WebClient wc = new WebClient())
                {
                    var json = wc.DownloadString("https://www.dhlottery.co.kr/common.do?method=getLottoNumber&drwNo="+count);
                    var jArray = JObject.Parse(json);
                    if (jArray["returnValue"].ToString() == "fail")
                        break;
                    Lotto temp =
                        new Lotto(jArray["drwtNo1"].ToString(),
                        jArray["drwtNo2"].ToString(), jArray["drwtNo3"].ToString(), jArray["drwtNo4"].ToString(),
                        jArray["drwtNo5"].ToString(), jArray["drwtNo6"].ToString(), jArray["bnusNo"].ToString(), jArray["drwNo"].ToString(),
                        jArray["drwNoDate"].ToString());
                    lottoBindingSource.Add(temp);
                    count++;
                }
            }
        }
    }
}
