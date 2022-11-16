namespace HelloMyCSharp03
{
    partial class MainForm
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.button_mbox = new System.Windows.Forms.Button();
            this.Input = new System.Windows.Forms.TextBox();
            this.button_customized = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.button_show = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.circularButton1 = new HelloMyCSharp03.CircularButton();
            this.SuspendLayout();
            // 
            // button_mbox
            // 
            this.button_mbox.Location = new System.Drawing.Point(25, 59);
            this.button_mbox.Name = "button_mbox";
            this.button_mbox.Size = new System.Drawing.Size(98, 23);
            this.button_mbox.TabIndex = 0;
            this.button_mbox.Text = "메세지 박스";
            this.button_mbox.UseVisualStyleBackColor = true;
            this.button_mbox.Click += new System.EventHandler(this.button_mbox_Click);
            // 
            // Input
            // 
            this.Input.Location = new System.Drawing.Point(86, 12);
            this.Input.Name = "Input";
            this.Input.Size = new System.Drawing.Size(156, 21);
            this.Input.TabIndex = 1;
            this.Input.TextChanged += new System.EventHandler(this.Input_TextChanged);
            // 
            // button_customized
            // 
            this.button_customized.Location = new System.Drawing.Point(144, 59);
            this.button_customized.Name = "button_customized";
            this.button_customized.Size = new System.Drawing.Size(98, 23);
            this.button_customized.TabIndex = 2;
            this.button_customized.Text = "맞춤 박스";
            this.button_customized.UseVisualStyleBackColor = true;
            this.button_customized.Click += new System.EventHandler(this.button_customized_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 12);
            this.label1.TabIndex = 3;
            this.label1.Text = "글자 입력";
            // 
            // button_show
            // 
            this.button_show.Location = new System.Drawing.Point(264, 59);
            this.button_show.Name = "button_show";
            this.button_show.Size = new System.Drawing.Size(98, 23);
            this.button_show.TabIndex = 4;
            this.button_show.Text = "그냥 창띄우기";
            this.button_show.UseVisualStyleBackColor = true;
            this.button_show.Click += new System.EventHandler(this.button_show_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(491, 172);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // circularButton1
            // 
            this.circularButton1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.circularButton1.FlatAppearance.BorderSize = 0;
            this.circularButton1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.circularButton1.Location = new System.Drawing.Point(204, 128);
            this.circularButton1.Name = "circularButton1";
            this.circularButton1.Size = new System.Drawing.Size(210, 192);
            this.circularButton1.TabIndex = 6;
            this.circularButton1.Text = "circularButton1";
            this.circularButton1.UseVisualStyleBackColor = false;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.circularButton1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button_show);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button_customized);
            this.Controls.Add(this.Input);
            this.Controls.Add(this.button_mbox);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button_mbox;
        private System.Windows.Forms.TextBox Input;
        private System.Windows.Forms.Button button_customized;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_show;
        private System.Windows.Forms.Button button1;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private CircularButton circularButton1;
    }
}

